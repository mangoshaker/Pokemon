#include "leaderLoader.h"
#include "../leaderGym.h"
#include "../../pokemonLoader/pokemonLoader.h"
#include "../../pokemon/pokemon.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace leaderGym;
using namespace pokemonLoader;
using namespace pokemon;
using namespace leaderLoader;

/**
 * @brief Charge tous les leaders depuis le fichier CSV 'leaders.csv'.
 * 
 * Chaque ligne doit contenir : Nom, Gymnase, Badge, [Pokemon1, ..., Pokemon6].
 * Les Pokémon sont recherchés dans la base principale (pokemon.csv).
 * 
 * @return std::vector<LeaderGym*> Liste de pointeurs vers les objets LeaderGym créés.
 * @throws std::runtime_error si le fichier est introuvable ou mal formé.
 */
vector<LeaderGym*> LeaderLoader::chargerDepuisCSV() {
    //ouvrir le fichier csv en lecture
    vector<LeaderGym*> leaders;
    ifstream fichier("entraineur/Ressources/leaders.csv");

    if (!fichier.is_open()) {
        throw runtime_error("Erreur : impossible d'ouvrir 'leaders.csv'");
    }

    string ligne;
    getline(fichier, ligne); // ignorer l'en-tête

    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        string nom, gymnase, badge;
        vector<string> nomsPokemon;
        string champ;

        // lecture des 3 premiers champs obligatoires
        if (!getline(ss, nom, ',') || !getline(ss, gymnase, ',') || !getline(ss, badge, ',')) {
            throw runtime_error("Erreur : ligne mal formée dans leaders.csv");
        }

        // lecture des noms des pokemon restants
        while (getline(ss, champ, ',')) {
            if (!champ.empty()) nomsPokemon.push_back(champ);
        }
        
        //creation du leader
        LeaderGym* leader = new LeaderGym(nom, gymnase, badge, nomsPokemon);
        leaders.push_back(leader);
    }

    fichier.close();
    return leaders;
}


/**
 * @brief Enregistre un nouveau leader dans le fichier 'leaders.csv'.
 * 
 * Les données sont ajoutées en fin de fichier sans effacer les précédentes.
 * 
 * @param leader Référence vers un objet LeaderGym à enregistrer.
 * @throws std::runtime_error si le fichier ne peut pas être ouvert en écriture.
 */
void LeaderLoader::enregistrerDansCSV(const LeaderGym& leader) {
    //ouvrir le fichier en mode ajout 
    ofstream fichier("entraineur/Ressources/leaders.csv", ios::app);
    if (!fichier.is_open()) {
        throw runtime_error("Erreur : impossible d'écrire dans 'leaders.csv'");
    }

    fichier << leader.getNom() << "," << leader.getGymnase() << "," << leader.getBadge();
    
    //ecrire la liste des pokemon de l'equipe
    for (Pokemon* p : leader.getEquipe()) {
        fichier << "," << p->getNom();
    }
    fichier << "\n";

    fichier.close();
}
