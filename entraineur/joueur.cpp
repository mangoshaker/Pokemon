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


//Getters
int Joueur::getNbBadges() const {return nb_badges; }
int Joueur::getNbGagne() const {return nb_gagne;}
int Joueur::getNbPerdu() const {return nb_perdu;}

//Setters incrementer 
void Joueur::ajouterGagne() { nb_gagne++ ; }
void Joueur::ajouterPerdu() { nb_perdu++;}



// Nouveaux getters et setters pour badges
/// @brief ajout d'un badge selon son type
/// @param badgeType 
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



/// @brief Affiche les stats du joueur dans la console
void Joueur::afficherStatistiques() const {
    std::cout << "\n=== Statistiques de " << getNom() << " ===" << std::endl;
    std::cout << " - Nombre de victoires : " << nb_gagne << std::endl;
    std::cout << " - Nombre de defaites  : " << nb_perdu << std::endl;
    std::cout << " - Badges obtenus (" << nb_badges << ") : ";

    bool aDesBadges = false;
    for (const auto& pair : badges) {
        if (pair.second) {
            std::cout << pair.first << " ";
            aDesBadges = true;
        }
    }

    if (!aDesBadges) {
        std::cout << "Aucun";
    }

    std::cout << std::endl;
}


