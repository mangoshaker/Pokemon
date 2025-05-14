#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "../entraineur/entraineur.h"
#include "../pokemon/pokemon.h"
#include "../pokemon/typeChart.h"
#include "../combat/combat.h"
#include "../entraineur/joueurLoader/joueurLoader.h"
#include "jeu.h"

using namespace std;
using namespace entraineur;
using namespace typechart;
using namespace pokemon;
using namespace combat;
using namespace joueurLoader;
using namespace jeu;

Jeu::Jeu(){
    JoueurLoader jloader;
    joueurs = jloader.getJoueurs(); 
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
        cout << "1. Voir l'equipe de Pokemon" << endl;
        cout << "2. Quitter" << endl;
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
                if (joueur) {
                    joueur->afficherEquipe();
                } else {
                    cout << "Aucun joueur actif." << endl;
                }
                cout << "\nAppuyez sur Entrée pour revenir au menu...";
                cin.ignore();
                cin.get();
                break;

            case 2:
                clearConsole();
                cout << "\nFin de la session. A bientot !" << endl;
                break;

            default:
                cout << "Choix invalide. Reessayer." << endl;
                break;
        }

    } while (choix != 2);
}


/// @brief Vide la console
void Jeu::clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }
    