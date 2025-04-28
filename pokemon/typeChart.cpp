#include "pokemon.h"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;
using namespace pokemon;
using namespace typechart;

TypeChart(){
    map<pair<string, string>, float> tablemult;
    //tablemult = fonction qui remplie la map
}

map<string,map<string,float>> fillMap(){

}

void chargerTypeChart(const string& filename) {
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

