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
        getline(ss, defenseur, ',');
        getline(ss, attaquant, ',');
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

/**
 * @brief Renvoie le multiplicateur de dégats en fonction des types du pokemon attaquant et ceux du defenseur
 */
float TypeChart::getMult(Pokemon* attaquant, Pokemon* defenseur){
    float mult = 1;
    const vector<string>& typesAtt = attaquant->getTypes();
    const vector<string>& typesDef = defenseur->getTypes();

    for (const string& typeA : typesAtt){
        for(const string& typeD: typesDef){
            mult*=getMultIndiv(typeA,typeD);
        }
    }
    
    return mult;
}

/**
 * @brief renvoie le multiplicateur associé à deux types
 */
float TypeChart::getMultIndiv(const string& type_att, const string& type_def) {
    auto it = tablemult.find({type_att, type_def});
    if (it != tablemult.end()) {
        return it->second;
    } else {
        return 1.0f; // Pas de faiblesse ou de résistance particulière
    }
}
