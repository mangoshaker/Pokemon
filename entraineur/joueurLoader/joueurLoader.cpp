#include "joueurLoader.h"
#include "../../pokemonLoader/pokemonLoader.h"
#include "../joueur.h"
#include "../../pokemon/pokemon.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace joueur;
using namespace pokemonLoader;
using namespace joueurLoader;
using namespace pokemon; 

vector<string> liste_badges = {"Feu", "Eau", "Roche", "Plante", "Électrik", "Psy"};


JoueurLoader::JoueurLoader(){
    joueurs = std::move(JoueurLoader::chargerDepuisCSV());
}

JoueurLoader::JoueurLoader(){
    joueurs = std::move(JoueurLoader::chargerDepuisCSV());
}

/**
 * @brief Lecture du fichier joueur.csv et création des objets Joueur
 * @throws std::runtime_error si le fichier est introuvable ou mal formé.
 */
 vector<Joueur*> JoueurLoader::chargerDepuisCSV() {
    vector<Joueur*> joueurs;
    ifstream fichier("entraineur/Ressources/joueur.csv");

    if (!fichier.is_open()) {
        throw runtime_error("Erreur : impossible d'ouvrir joueur.csv");
    }

    string ligne;
    getline(fichier, ligne); // ignorer l'en-tête

    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        string nom;
        vector<string> nomsPokemon;
        string champ;

        // Lecture du nom
        if (!getline(ss, nom, ',')) {
            throw runtime_error("Erreur : ligne mal formée (nom manquant)");
        }

        // Lecture des 6 Pokémon max
        for (int i = 0; i < 6; ++i) {
            if (getline(ss, champ, ',')) {
                if (!champ.empty()) nomsPokemon.push_back(champ);
            }
        }

        // Création du joueur
        Joueur* j = new Joueur(nom, nomsPokemon);

        // Lecture des 6 badges
        for (const string& badge : liste_badges) {
            if (getline(ss, champ, ',')) {
                if (champ == "1") {
                    j->ajouterBadge(badge);
                }
            }
        }

        joueurs.push_back(j);
    }

    fichier.close();
    return joueurs;
}

 /**
  * @brief ajoute un joueur a joueur.csv
  * @throws std::runtime_error si le fichier ne peut pas etre ouvert en ecriture
  */
  void JoueurLoader::enregistrerDansCSV(const Joueur& joueur)
  {
    ofstream fichier("entraineur/Ressources/joueur.csv", ios::app); 
    //ouvrir le fichier joueur.csv en mode ajour (append) pour enregistrer un nouveau joueur

    if (!fichier.is_open()) {
        throw runtime_error("Erreur : impossible d'écrire dans joueur.csv");
    }

    // Nom + pokémons
    fichier << joueur.getNom();
    for (Pokemon* p : joueur.getEquipe()) {
        fichier << "," << p->getNom();
    }

    // Remplir les cases Pokémon manquantes (si < 6)
    int nbPokemons = joueur.getEquipe().size();
    for (int i = nbPokemons; i < 6; ++i) {
        fichier << ",";
    }

    // Ajout des badges sous forme de 0/1
    const map<string, bool>& badges = joueur.getBadges();
    for (const string& badge : liste_badges) {
        fichier << "," << (badges.count(badge) && badges.at(badge) ? "1" : "0");
    }

    fichier << "\n";
    fichier.close();
}
  /// @brief Accède aux joueurs
  /// @return vecteur : joueurs
  const vector<Joueur*>& JoueurLoader::getJoueurs() const {
    return joueurs;
}

/// @brief Création d'un joueur
/// @param nouveau Joueur
void JoueurLoader::ajouterJoueur(Joueur* nouveau) {
    if (nouveau != nullptr) {
        joueurs.push_back(nouveau);
        enregistrerDansCSV(*nouveau);
    }
}