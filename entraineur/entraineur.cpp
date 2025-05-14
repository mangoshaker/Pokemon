#include "entraineur.h"
#include "../pokemon/pokemon.h"
#include <iostream>
#include <algorithm> //pour std::swap
#include <string>


using namespace std;
using namespace entraineur;
using namespace pokemon;

//constructeur, getters, setters
Entraineur::Entraineur::Entraineur(const string& Nom)
{
    nom=Nom; 
}

string Entraineur::Entraineur::getNom() const{
    return nom; 
}

const vector<pokemon::Pokemon*>& Entraineur::Entraineur::getEquipe() const
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

void Entraineur::setGagnant(bool etat) {
    gagnant = etat;
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

/// @brief Vérifie s'il est gagnat (get)
/// @return bool
bool Entraineur::estGagnant() const {
    return gagnant;
}

/// @brief Affiche un message quand est perdant
void Entraineur::Entraineur::interagir()
{
    if (!gagnant) {
        cout<< "L'entraineur " << nom << " dit : Tu m'as vaincu, bien joué !"<<endl;
    } else {
        cout<< "Tu ne peux pas interagir avec " << nom << " tant qu’il n’est pas vaincu."<<endl;
    }
}


/**
 * @brief: liberation memoire 
 */
Entraineur::~Entraineur() {
    for (pokemon::Pokemon*& p : equipe) {
        if (p != nullptr) {
            delete p;
            p = nullptr;
        }
    }
}

/// @brief Affiche la composition de l'équipe dans la console
void Entraineur::afficherEquipe() const {
    if (equipe.empty()) {
        cout << "Aucun Pokemon dans l'equipe." << endl;
        return;
    }

    cout << "\n--- Equipe de " << nom << " ---" << endl;

    for (size_t i = 0; i < equipe.size(); ++i) {
        Pokemon* p = equipe[i];
        p->infoPokemon();
        cout << endl;
    }
}

/// @brief Affiche les HP des pokémons de l'équipe
void Entraineur::afficherHP() const {
    if (equipe.empty()) {
        cout << "Aucun Pokemon dans l'equipe." << endl;
        return;
    }

    cout << "\n--- HP des Pokemon de " << nom << " ---" << endl;
    for (size_t i = 0; i < equipe.size(); ++i) {
        Pokemon* p = equipe[i];
        cout << "[" << i + 1 << "] " << p->getNom() << " - HP : " << p->getHP() << endl;
    }
}





