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

/// @brief Gère le menu et l'affichage console du jeu
void Jeu::Menu() {
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
        cout << "\nSelectionnez un joueur (1 à " << joueurs.size() << ") : ";
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

    // TODO : menu principal
}

