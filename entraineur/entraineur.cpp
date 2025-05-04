#include "entraineur.h"
#include <iostream>
#include <algorithm> //pour std::swap
#include <string>


using namespace std;
using namespace entraineur;

Entraineur::Entraineur::Entraineur(const string& Nom)
{
    nom=Nom; 
}

string Entraineur::Entraineur::getNom() const{
    return nom; 
}

vector<pokemon::Pokemon*>& Entraineur::Entraineur::getEquipe()
{
    return equipe;
}

/**
 * @brief : renvoie le 1er pokemon dans l'equipe
 */
pokemon::Pokemon* Entraineur::Entraineur::getPokemonSelec()
{
    if(!equipe.empty())
    {
        return equipe[0];
    }
    return nullptr;
}


/** 
* @brief permet d'ajouter un pokemon s'il y en a moins que 6 dans une equipe 
*/
void Entraineur::Entraineur::ajouterPokemon(pokemon::Pokemon* p)
{
    if(equipe.size() < 6)
    {
        equipe.push_back(p);
    }
    else 
    {
        cout<< "Equipe deja complete (6 Pokemon max)" << endl;
    }
}

/**
 * @brief : changement de position de 2 Pokemon dans l'equipe
 */

void Entraineur::Entraineur::modifierEquipe(int pos1, int pos2)
{
    if (pos1 >=0 && pos1 < equipe.size() && pos2 >= 0 && pos2 < equipe.size() )
    {
        swap(equipe[pos1], equipe[pos2]);
    }
    else{
        cout<<"Positions invalides pour la permutation."<<endl;
    }
}



string Entraineur::Entraineur::interagir()
{
    return "L'entraineur " + nom + " vous observe attentivement.";
}


/**
 * @brief: liberation memoire 
 */
Entraineur::Entraineur::~Entraineur()
{
    for(pokemon::Pokemon* p : equipe)
    {
        delete p; 
    }
}



