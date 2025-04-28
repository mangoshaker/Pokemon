#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <vector>
#include <string>

namespace pokemon {
class Pokemon {
public:
    Pokemon(std::string Nom, int HP, std::string attaque, int degat, std::string type1, std::string type2="");
    virtual void attaquer(Pokemon* cible);
    virtual std::string interagir();
    void infoPokemon();

protected:
    std::string nom;
    vector<std::string> types;
    int HP;
    std::string attaque;
    int degat;
};
}

#endif
