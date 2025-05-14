#ifndef JOUEUR_H
#define JOUEUR_H
#include "../entraineur/entraineur.h"
#include <map>
#include <string>
#include <vector>

namespace joueur{
class Joueur : public entraineur::Entraineur{
private:
    int nb_badges;
    int nb_gagne;
    int nb_perdu;
    std::map<std::string, bool> badges;

public:
    // Constructeur
    /// @brief  constructeur du joueur
    /// @brief initialise les compteurs, l'équipe de Pokémon, et les badges
    /// @param nom 
    /// @param nomPokemon 
    Joueur(const std::string& nom, const std::vector<std::string>& nomsPokemon);

    //getters
    int getNbBadges() const;
    int getNbGagne() const;
    int getNbPerdu() const;

    //setters /ajouts
    void ajouterGagne();
    void ajouterPerdu();
   
    // Nouveaux setters et getters pour le comptage de badge
    /// @brief ajout d'un badge selon son type
    /// @param badgeType 
    void ajouterBadge(const std::string& badgeType);

    /// @brief Vérifie si le joueur a un badge donné
    /// @param badgeType Type du badge à vérifier (ex: "Feu", "Eau", ...)
    /// @return true si le badge est obtenu, false sinon
    bool aLeBadge(const std::string& badgeType) const;

    /// @brief Renvoie la map des badges du joueur
    /// @return Référence constante vers la map<string, bool> badges
    const std::map<std::string, bool>& getBadges() const;

    /// @brief check si le joueur a recupere tous les badges
    /// @return 
    bool estPretPourAffronterMaitre() const; 

    /// @brief Affiche les stats du joueur dans la console
    void afficherStatistiques() const;

};
}
#endif