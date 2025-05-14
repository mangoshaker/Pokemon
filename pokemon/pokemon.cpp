#include "pokemon.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

using namespace pokemon;

Pokemon::Pokemon(std::string Nom, int HP, std::string attaque, int degat, std::string type1, std::string type2) {
    this->nom = Nom;
    this->HP = HP;
    this->attaque = attaque;
    this->degat = degat;
    types.push_back(type1);
    if (!type2.empty()) types.push_back(type2);
}

/// @brief Accède aux types du pokemon
/// @return vecteur contenant le ou les types du pokemon
const vector<string>& Pokemon::getTypes() const{
    return this->types;
}
/// @brief Accède au nom du pokemon
/// @return string = nom du pokemon
const string Pokemon::getNom() const {
    return nom;
}

/// @brief Accède aux HP du pokemon
/// @return int = HP de départ
const int Pokemon::getHP()const{
    return HP;
}

/// @brief Accède aux dégâts provoqués par l'attaque du pokemon
/// @return int = dégât provoqué
const int Pokemon::getDegat()const{
    return degat;
}

void Pokemon::setDegat(float nouveauDegat) {
    this->degat = nouveauDegat;
}

/**
 *  @brief affiche une phrase signifiant l'attaque - fct peut etre à modifier
 */
void Pokemon::attaquer(Pokemon* cible) {
    cout << nom << " attaque " << cible->nom << " avec " << attaque << " !" << endl;
}


/// @brief affiche un petit message sur le pokemon
void Pokemon::interagir()
{
    string message = nom.substr(0, 4) + nom.substr(0, 4) + ", je suis " + nom + "!";
    cout << message << endl;
}

/// @brief affiche les infos des pokemons
void Pokemon::infoPokemon()
{
    cout << "Nom: " << nom << ", HP: " << HP << ", Attaque: " << attaque << ", Degats: " << degat << endl;
    for (string s : types) {
        cout << "Type: " << s << endl;
    }
}

Pokemon::~Pokemon() {
}



