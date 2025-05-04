#include "pokemon.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace pokemon; 

Pokemon::Pokemon(string Nom, int hp, string Attaque, int Degat, string type1, string type2)
{
    nom = Nom;
    HP = hp;
    attaque = Attaque;
    degat = Degat;
    types.push_back(type1);
    if (type2 != "") types.push_back(type2); 
}

/**
 * @brief Retourne les types du pokemon
 */
const vector<string>& Pokemon::getTypes() const{
    return this->types;
}

/**
 * @brief Retourne les types du pokemon
 */
const vector<string>& Pokemon::getTypes() const{
    return this->types;
}

 /**
  *  @brief affiche une phrase signifiant l'attaque - fct peut etre à modifier
 */
void Pokemon::attaquer(Pokemon* cible) {
    cout << nom << " attaque " << cible->nom << " avec " << attaque << " !" << endl;
}

/**
 * @brief affiche un petit message sur le pokemon
 * @return string contenant le message
 */
string Pokemon::interagir()
{
    string message = nom.substr(0, 4) + nom.substr(0, 4) + ", je suis " + nom + "!";
    cout << message << endl;
    return message;
}

/**
 * @brief affiche les infos des pokemons
 */
void Pokemon::infoPokemon()
{
    cout << "Nom: " << nom << ", HP: " << HP << ", Attaque: " << attaque << ", Degats: " << degat << endl;
    for (string s : types) {
        cout << "Type: " << s << endl;
    }
}

string Pokemon::getNom() const {
    return nom;
}

