#include <iostream>
#include <vector>
#include <string>
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
    cout << "         POKÉMON - THE GAME        " << endl;
    cout << "===================================" << endl;
    cout << "\nAppuyez sur Entrée pour commencer...";
    cin.ignore(); // attend que l'utilisateur appuie sur "entrée"

    system("cls"); // nettoie la console (Windows) ; sur Linux : system("clear");

    cout << "\nChargement des joueurs...\n" << endl;

    // Afficher les joueurs existants
    if (Aff_Joueurs()) {
        int choix = 0;
        do {
            cout << "\nSélectionnez un joueur existant (1 à " << joueurs.size() << "), ou 0 pour en créer un nouveau : ";
            cin >> choix;

            if (choix < 0 || choix > (int)joueurs.size()) {
                cout << "Choix invalide, réessayez." << endl;
            }

        } while (choix < 0 || choix > (int)joueurs.size());

        if (choix == 0) {
            creerNouveauJoueur();
        } else {
            joueur = joueurs[choix - 1];
            cout << "\nBienvenue, " << joueur->getNom() << " !" << endl;
        }

    } else {
        // Aucun joueur => créer un nouveau
        creerNouveauJoueur();
    }

    // Optionnel : afficher un menu principal ensuite
}
