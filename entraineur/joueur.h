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
    Joueur(const std::string& nom, const std::vector<std::string>& nomsPokemon);
   
    // Nouveaux setters et getters pour le comptage de badge
    void ajouterBadge(const std::string& badgeType);
    bool aLeBadge(const std::string& badgeType) const;
    const std::map<std::string, bool>& getBadges() const;
    /// @brief check si le joueur a recupere tous les badges
    /// @return 
    bool estPretPourAffronterMaitre() const; 


    
    // Nouveaux setters et getters pour le comptage de badge
    void ajouterBadge(const std::string& badgeType);
    bool aLeBadge(const std::string& badgeType) const;
    const std::map<std::string, bool>& getBadges() const;
    /// @brief check si le joueur a recupere tous les badges
    /// @return 
    bool estPretPourAffronterMaitre() const; 

    //getters
    int getNbBadges() const;
    int getNbGagne() const;
    int getNbPerdu() const;

    //setters /ajouts
    void ajouterBadges();
    void ajouterGagne();
    void ajouterPerdu();

    /// @brief Affiche les stats du joueur dans la console
    void afficherStatistiques() const;

};
}
#endif