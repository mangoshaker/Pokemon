#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <vector>
#include <string>
#include "../interaction/interaction.h"

using namespace interaction;

namespace pokemon {
class Pokemon : public Interaction {
public:
    Pokemon(std::string Nom, int HP, std::string attaque, int degat, std::string type1, std::string type2="");
    ///@brief affiche une phrase signifiant l'attaque - fct peut etre à modifier
    virtual void attaquer(Pokemon* cible);    
    /// @brief affiche un petit message sur le pokemon
    virtual void interagir() override;
    /// @brief affiche les infos des pokemons
    void infoPokemon();
    /// @brief Accède aux types du pokemon
    /// @return vecteur contenant le ou les types du pokemon
    const std::vector<std::string>& getTypes() const;
    /// @brief Accède au nom du pokemon
    /// @return string = nom du pokemon 
    const std::string getNom() const;
    /// @brief Accède aux HP du pokemon
    /// @return int = HP de départ
    const int getHP()const;
    /// @brief Accède aux dégâts provoqués par l'attaque du pokemon
    /// @return int = dégât provoqué
    const int getDegat()const;
    virtual ~Pokemon();
    /// @brief pour pouvoir creer une clone pour le maitre (calcul de *1.25 sur le degat)
    /// @param nouveauDegat 
    void setDegat(float nouveauDegat);

protected:
    std::string nom;
    std::vector<std::string> types;
    int HP;
    std::string attaque;
    int degat;


};
}

#endif
