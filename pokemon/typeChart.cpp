#include "pokemon.h"
#include "typeChart.h"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;
using namespace pokemon;
using namespace typechart;

map<pair<string, string>, float> tablemult;

TypeChart::TypeChart(){
    creationTypeChart("pokemon/Ressources/tabfaiblesseresistance.csv");
}

/**
 * @brief Remplie la map des faiblesses/résistances
 */
void TypeChart::creationTypeChart(const string& filename) {
    ifstream fichier(filename);
    if (!fichier.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << filename << endl;
        return;
    }

    string ligne;
    getline(fichier, ligne); // Lire l'en-tête et l'ignorer

    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        string attaquant, defenseur, multiplicateurStr;
        
        // Lire les trois colonnes séparées par des virgules
        getline(ss, attaquant, ',');
        getline(ss, defenseur, ',');
        getline(ss, multiplicateurStr, ',');

        float multiplicateur = stof(multiplicateurStr);

        tablemult[{attaquant, defenseur}] = multiplicateur;
    }

    fichier.close();
}

/**
 * @brief Affiche TypeChart
 */
void TypeChart::afficherTypeChart() {
    for (const auto& entry : tablemult) {
        cout << entry.first.first << " -> " << entry.first.second << " : " << entry.second << endl;
    }
}
