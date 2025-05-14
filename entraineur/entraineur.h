#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include <string>
#include <vector>
#include <string> 
#include "../pokemon/pokemon.h"
#include "../interaction/interaction.h"

using namespace interaction;

namespace entraineur{ 
class Entraineur : public Interaction{
protected:
    std::string nom;
    std::vector<pokemon::Pokemon*> equipe; //max 6 Pokemon   
public:
    Entraineur(const std::string& nom);

    //Getters
    std::string getNom() const;
    const std::vector<pokemon::Pokemon*>& getEquipe() const;
    pokemon::Pokemon* getPokemonSelec(); //renvoie le 1er pokemon de la liste

    //setter
    void setGagnant(bool etat);

    //Gestion equipe 

    /// @brief permet d'ajouter un pokemon s'il y en a moins que 6 dans une equipe
    /// @param p 
    void ajouterPokemon(pokemon::Pokemon* p);  //ajout d'un nouveau pokemon dans l'equipe de joueur

    /// @brief : changement de position de 2 Pokemon dans l'equipe
    /// @param pos1 
    /// @param pos2 
    void modifierEquipe(int pos1, int pos2); //changement d'ordre des pokemon deja dans l'equipe

    /// @brief Affiche la composition de l'équipe dans la console
    void afficherEquipe() const;

    /// @brief Affiche les HP des pokémons de l'équipe
    void afficherHP() const;

    //Methode virtuelle pour l'interaction 
    virtual void interagir() override; 

    /// @brief Vérifie s'il est gagnat (get)
    /// @return bool
    bool estGagnant() const  ;

    

    /// @brief liberation memoire 
    virtual ~Entraineur(); //liberation memoire
private:
    bool gagnant = true;
};
}

#endif



