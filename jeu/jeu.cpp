#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>
#include <limits>
#include "jeu.h"
#include "../entraineur/entraineur.h"
#include "../pokemon/pokemon.h"
#include "../pokemon/typeChart.h"
#include "../combat/combat.h"
#include "../entraineur/joueurLoader/joueurLoader.h"
#include "../entraineur/leaderGym.h"
#include "../entraineur/leaderLoader/leaderLoader.h"
#include "../entraineur/maitre.h"
#include "../entraineur/maitreLoader/maitreLoader.h"

using namespace std;
using namespace entraineur;
using namespace typechart;
using namespace pokemon;
using namespace combat;
using namespace joueurLoader;
using namespace jeu;
using namespace leaderGym;
using namespace leaderLoader;
using namespace maitre;
using namespace maitreLoader;

vector<leaderGym::LeaderGym*> leaders;
std::vector<maitre::Maitre*> maitres;

Jeu::Jeu(){
    JoueurLoader jloader;
    joueurs = jloader.getJoueurs(); 
    LeaderLoader loader;
    leaders = loader.chargerDepuisCSV();
    MaitreLoader mloader;
    maitres = mloader.chargerDepuisCSV();
}

/// @brief Affiche tous les joueurs
/// @return bool : True si joueurs existants, False sinon
bool Jeu::Aff_Joueurs() {
    if (joueurs.empty()) {
        cout << "\nAucun joueur enregistré." << endl;
        return false;
    }

    cout << "\n=== Liste des joueurs disponibles ===" << endl;
    for (size_t i = 0; i < joueurs.size(); ++i) {
        cout << i + 1 << ". " << joueurs[i]->getNom() << endl;
    }

    return true;
}

/// @brief Gère le jeu
void Jeu::StartJeu() {
    cout << "===================================" << endl;
    cout << "         POKEMON - THE GAME        " << endl;
    cout << "===================================" << endl;
    cout << "\nAppuyez sur Entree pour commencer...";
    cin.ignore(); // attend une touche

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    cout << "\nChargement des joueurs...\n" << endl;

    // Afficher les joueurs
    if (!Aff_Joueurs()) {
        cout << "\nAucun joueur disponible. Veuillez en créer un manuellement via joueur.csv." << endl;
        cout << "Fin du jeu." << endl;
        return; //  Sort du menu (jeu non lancé)
    }

    int choix = 0;
    do {
        cout << "\nSelectionnez un joueur (1 a " << joueurs.size() << ") : ";
        cin >> choix;

        if (cin.fail() || choix < 1 || choix > (int)joueurs.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Choix invalide. Veuillez reessayer." << endl;
            choix = 0;
        }

    } while (choix == 0);

    joueur = joueurs[choix - 1];
    #ifdef _WIN32
    system("cls");
    #else
        system("clear");
    #endif
    cout << "\nBienvenue, " << joueur->getNom() << " !" << endl;

    MenuPrincipal();
}

/// @brief Affiche et gère le menu principal
void Jeu::MenuPrincipal() {
    int choix = 0;

    do {
        clearConsole();
        cout << "\n========= MENU PRINCIPAL =========" << endl;

        // 1. Affichage de base
        cout << "1. Voir l'equipe de Pokemon" << endl;
        cout << "2. Afficher les HP des Pokemon" << endl;

        // 2. Gestion d'equipe
        cout << "3. Changer l'ordre des Pokemon dans l'equipe" << endl;

        // 3. Statistiques
        cout << "4. Afficher les statistiques du joueur" << endl;

        // 4. Combats
        cout << "5. Affronter un leader de gym" << endl;
        cout << "6. Affronter un Maitre Pokemon" << endl;

        // 5. Interactions
        cout << "7. Interagir avec les Pokemon ou entraineurs vaincus" << endl;

        // 6. Quitter
        cout << "8. Quitter le jeu" << endl;

        cout << "Choix : ";
        cin >> choix;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choix = -1;
        }

        switch (choix) {
            case 1:
                clearConsole();
                joueur->afficherEquipe();
                break;

            case 2:
                clearConsole();
                joueur->afficherHP();
                break;

            case 3: {
                clearConsole();
                joueur->afficherEquipe();
                int i, j;
                cout << "\nEntrez le numero du 1er Pokemon a echanger : ";
                cin >> i;
                cout << "Entrez le numero du 2e Pokemon a echanger : ";
                cin >> j;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entree invalide." << endl;
                } else {
                    joueur->modifierEquipe(i - 1, j - 1);
                }
                break;
            }

            case 4:
                clearConsole();
                joueur->afficherStatistiques();
                break;

            case 5:
                lancerCombatContreLeader();
                break;

            case 6:
                affronterMaitre();
                break;

            case 7:
                interagirAvecElements();
                break;

            case 8:
                clearConsole();
                cout << "\nFin du jeu. A bientot !" << endl;
                return;

            default:
                cout << "Choix invalide. Reessayer." << endl;
                break;
        }

        cout << "\nAppuyez sur Entree pour revenir au menu...";
        cin.ignore();
        cin.get();

    } while (true);
}


/// @brief Affiche les leaders disponibles
void Jeu::afficherLeadersDisponibles() const {
    cout << "=== Leaders de gym disponibles ===" << endl;
    for (size_t i = 0; i < leaders.size(); ++i) {
        cout << i + 1 << ". " << leaders[i]->getNom()
             << " - Gym : " << leaders[i]->getGymnase()
             << " - Badge : " << leaders[i]->getBadge() << endl;
    }
}

/// @brief Lance un combat joueur vs leader
void Jeu::lancerCombatContreLeader() {
    clearConsole();
    afficherLeadersDisponibles();

    int choixLeader;
    cout << "\nChoisissez un leader (1 a " << leaders.size() << ") : ";
    cin >> choixLeader;

    if (cin.fail() || choixLeader < 1 || choixLeader > (int)leaders.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Choix invalide." << endl;
        return;
    }

    LeaderGym* adversaire = leaders[choixLeader - 1];

    cout << "\n--- Combat contre " << adversaire->getNom() << " ---" << endl;

    Combat combat(joueur, adversaire);
    Entraineur* gagnant = combat.start_partie();

    if (gagnant == joueur) {
        cout << "\nVictoire ! Vous remportez le badge : " << adversaire->getBadge() << endl;
        if (!joueur->aLeBadge(adversaire->getBadge())) {
            joueur->ajouterBadge(adversaire->getBadge());
        }
        joueur->ajouterGagne();
        adversaire->setGagnant(false); // marque comme battu
    } else {
        cout << "\nDefaite contre " << adversaire->getNom() << "." << endl;
        joueur->ajouterPerdu();
    }

}

/// @brief Affronte un maitre aléatoire
void Jeu::affronterMaitre() {
    if (!joueur->estPretPourAffronterMaitre()) {
        cout << "\nVous devez posseder tous les badges avant d'affronter un Maitre." << endl;
        return;
    }

    if (maitres.empty()) {
        cout << "Aucun maitre disponible." << endl;
        return;
    }

    srand(time(nullptr));
    int index = rand() % maitres.size();
    Maitre* adversaire = maitres[index];

    clearConsole();
    cout << "--- Combat final contre le Maitre " << adversaire->getNom() << " ---" << endl;

    Combat combat(joueur, adversaire);
    Entraineur* gagnant = combat.start_partie();

    if (gagnant == joueur) {
        cout << "\nFELICITATIONS ! Vous avez vaincu le Maitre " << adversaire->getNom() << " !" << endl;
        joueur->ajouterGagne();
    } else {
        cout << "\nVous avez perdu contre le Maitre... Reessayez plus tard." << endl;
        joueur->ajouterPerdu();
    }
}

/// @brief Interagit soit avec un pokemon ou soit un leader de gym vaincu
void Jeu::interagirAvecElements() {
    clearConsole();

    cout << "=== INTERACTIONS DISPONIBLES ===" << endl;

    // 1. Pokémon du joueur
    cout << "\n[Pokémon dans l'équipe du joueur]" << endl;
    for (Pokemon* p : joueur->getEquipe()) {
        cout << "- ";
        p->interagir();  // méthode implémentée dans la classe Pokemon
    }

    // 2. Entraîneurs vaincus
    cout << "\n[Entraîneurs déjà battus]" << endl;
    bool trainerFound = false;
    for (LeaderGym* l : leaders) {
        if (!l->estGagnant()) {  // donc il a perdu contre le joueur
            cout << "- ";
            l->interagir(joueur);  // méthode d'interaction personnalisée
            trainerFound = true;
        }
    }

    if (!trainerFound) {
        cout << "Aucun entraîneur vaincu pour le moment." << endl;
    }
}

/// @brief Vide la console
void Jeu::clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }
    