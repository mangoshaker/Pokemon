#include "maitreLoader.h"
#include "../maitre.h"
#include "../../pokemonLoader/pokemonLoader.h"
#include "../../pokemon/pokemon.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace maitre;
using namespace maitreLoader;
using namespace pokemonLoader;
using namespace pokemon;

/**
 * @brief Charge tous les maîtres Pokémon depuis le fichier CSV 'maitres.csv'.
 * 
 * Chaque ligne doit contenir : Nom, [Pokemon1, ..., Pokemon6]
 * Les Pokémon sont recherchés dans la base principale (pokemon.csv).
 * 
 * @return std::vector<maitre::Maitre*> Liste de pointeurs vers les objets Maitre créés.
 * @throws std::runtime_error si le fichier est introuvable ou mal formé.
 */
vector<Maitre*> MaitreLoader::chargerDepuisCSV() {
    vector<Maitre*> maitres;
    ifstream fichier("entraineur/Ressources/maitres.csv");

    if (!fichier.is_open()) {
        throw runtime_error("Erreur : impossible d'ouvrir 'maitres.csv'");
    }

    string ligne;
    getline(fichier, ligne); // ignorer l'en-tête

    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        string nom;
        vector<string> nomsPokemon;
        string champ;

        // lecture du nom du maître
        if (!getline(ss, nom, ',')) {
            throw runtime_error("Erreur : nom du maître manquant ou ligne mal formée dans maitres.csv.");
        }

        // lecture des noms des pokémon
        while (getline(ss, champ, ',')) {
            if (!champ.empty()) nomsPokemon.push_back(champ);
        }

        // création du maître
        Maitre* m = new Maitre(nom, nomsPokemon);
        maitres.push_back(m);
    }

    fichier.close();
    return maitres;
}

/**
 * @brief Enregistre un maître dans le fichier 'maitres.csv'.
 * 
 * Ajoute un enregistrement en fin de fichier sans écraser les précédents.
 * 
 * @param maitre Référence vers un objet Maitre à enregistrer.
 * @throws std::runtime_error si le fichier ne peut pas être ouvert en écriture.
 */
void MaitreLoader::enregistrerDansCSV(const Maitre& maitre) {
    ofstream fichier("entraineur/Ressources/maitres.csv", ios::app);

    if (!fichier.is_open()) {
        throw runtime_error("Erreur : impossible d'écrire dans 'maitres.csv'");
    }

    fichier << maitre.getNom();
    for (Pokemon* p : maitre.getEquipe()) {
        fichier << "," << p->getNom();
    }

    fichier << "\n";
    fichier.close();
}
