#include "joueur.h"
#include <iostream>
#include <string>
#include "../pokemonLoader/pokemonLoader.h"

using namespace std;
using namespace joueur;
using namespace pokemonLoader;


// Constructeur
/// @brief  constructeur du joueur
/// @brief initialise les compteurs, l'équipe de Pokémon, et les badges
/// @param nom 
/// @param nomPokemon 
Joueur::Joueur(const string& nom, const vector<string>& nomPokemon)
    : Entraineur(nom), nb_badges(0), nb_gagne(0), nb_perdu(0) {

    vector<pokemon::Pokemon*> base = PokemonLoader::chargerDepuisCSV();

    // Rechercher et ajouter les Pokémon correspondant aux noms fournis
    for (const string& nomRecherche : nomPokemon) {
        for (pokemon::Pokemon* p : base) {
            if (p->getNom() == nomRecherche) {
                ajouterPokemon(p);
                break;
            }
        }
    }

    // Initialisation des badges à false (aucun badge au début)
    vector<string> types = {"Feu", "Eau", "Roche", "Plante", "Électrik", "Psy"};
    for (const string& type : types) {
        badges[type] = false;
    }
}


// Nouveaux getters et setters pour badges
void Joueur::ajouterBadge(const string& badgeType) {
    if (!badges[badgeType]) {
        badges[badgeType] = true;
        nb_badges++;
    }
}


/// @brief Vérifie si le joueur a un badge donné
/// @param badgeType Type du badge à vérifier (ex: "Feu", "Eau", ...)
/// @return true si le badge est obtenu, false sinon
bool Joueur::aLeBadge(const string& badgeType) const {
    auto it = badges.find(badgeType);
    return (it != badges.end()) ? it->second : false;
}

/// @brief Renvoie la map des badges du joueur
/// @return Référence constante vers la map<string, bool> badges
const map<string, bool>& Joueur::getBadges() const {
    return badges;
}


/// @brief check si le joueur a recupere tous les badges
/// @return 
bool Joueur::estPretPourAffronterMaitre() const {
    vector<string> requis = {"Feu", "Eau", "Roche", "Plante", "Électrik", "Psy"};

    for (const string& badge : requis) {
        auto it = badges.find(badge);
        if (it == badges.end() || !it->second) {
            return false;  // Un badge manquant
        }
    }
    return true;  // Tous les badges présents
}



//Getters
int Joueur::getNbBadges() const {return nb_badges; }
int Joueur::getNbGagne() const {return nb_gagne;}
int Joueur::getNbPerdu() const {return nb_perdu;}

//Setters incrementer 
void Joueur::ajouterBadges() { nb_badges++; }
void Joueur::ajouterGagne() { nb_gagne++ ; }
void Joueur::ajouterPerdu() { nb_perdu++;}





