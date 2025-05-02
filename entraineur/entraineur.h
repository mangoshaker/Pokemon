#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include <string>
#include <vector>
#include <string> 
#include "../pokemon/pokemon.h"

namespace Entraineur{ 
class Entraineur{
protected:
    std::string nom;
    std::vector<pokemon::Pokemon*> equipe; //max 6 Pokemon

public:
    Entraineur(const std::string& nom);

    //Getters
    std::string getNom() const;
    std::vector<pokemon::Pokemon*>& getEquipe();
    pokemon::Pokemon* getPokemonSelec(); //renvoie le 1er pokemon de la liste

    //Gestion equipe 
    void ajouterPokemon(pokemon::Pokemon* p);  //ajout d'un nouveau pokemon dans l'equipe de joueur
    void modifierEquipe(int pos1, int pos2); //changement d'ordre des pokemon deja dans l'equipe

    //Methode virtuelle pour l'interaction 
    virtual std::string interagir();

    virtual ~Entraineur(); //liberation memoire

};
}

#endif



