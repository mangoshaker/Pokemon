#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>

using namespace std;

class Pokemon {
    public:
        Pokemon(string Nom, int HP, string attaque, int degat, string type1, string type2="");
        virtual void attaquer(Pokemon* cible);
        virtual string interagir();
        
        string nom;
        vector<string> types;
        int HP;
        string attaque;
        int degat;        
};

#endif