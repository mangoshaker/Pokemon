#ifndef JOUEUR_H
#define JOUEUR_H
#include "../entraineur/entraineur.h"

namespace joueur{
class Joueur : public entraineur::Entraineur{
private:
    int nb_badges;
    int nb_gagne;
    int nb_perdu;

public:
    Joueur(const std::string& nom, const std::vector<std::string>& nomsPokemon);

    //getters
    int getNbBadges() const;
    int getNbGagne() const;
    int getNbPerdu() const;

    //setters /ajouts
    void ajouterBadges();
    void ajouterGagne();
    void ajouterPerdu();

   

};
}
#endif