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

JoueurLoader::JoueurLoader(){
    joueurs = std::move(JoueurLoader::chargerDepuisCSV());
}

/**
 * @brief lecture de joueur.csv et creation des objets joueur
 * @throws std::runtime_error si le fichier est introuvable ou inaccessible.
 */
 vector<Joueur*> JoueurLoader::chargerDepuisCSV() {
    vector<Joueur*> joueurs;
    ifstream fichier("entraineur/Ressources/joueur.csv");

    if(!fichier.is_open()) {
        throw runtime_error("Error : impossible d'ouvrir le fichier joueur.csv");
    }

    string ligne;
    getline(fichier, ligne); // ignorer l'en-tete 

    while(getline(fichier, ligne)) {
        stringstream ss(ligne);
        string nom;
        vector<string> nomsPokemon;
        string champ;

        if (!getline(ss, nom, ',')) {
            throw runtime_error("Erreur : nom du joueur manquant ou ligne mal formee dans le fichier joueur.csv. ");
        }

        while (getline(ss, champ, ',')) {
            if(!champ.empty()) nomsPokemon.push_back(champ);
        }
        
        Joueur* j = new Joueur(nom, nomsPokemon);
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

    if(!fichier.is_open()) {
        throw runtime_error("Erreur : impossible d'ecrire dans le fichier joueur.csv"); 
    }

    fichier << joueur.getNom();
    for(Pokemon* p : joueur.getEquipe()) {
        fichier << "," << p->getNom(); 
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