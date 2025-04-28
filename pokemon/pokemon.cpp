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

void Pokemon::attaquer(Pokemon* cible) {
    cout << nom << " attaque " << cible->nom << " avec " << attaque << " !" << endl;
}

string Pokemon::interagir()
{
    string message = nom.substr(0, 4) + nom.substr(0, 4) + ", je suis " + nom + "!";
    cout << message << endl;
    return message;
}

void Pokemon::infoPokemon()
{
    cout << "Nom: " << nom << ", HP: " << HP << ", Attaque: " << attaque << ", Dégats: " << degat << endl;
    for (string s : types) {
        cout << "Type: " << s << endl;
    }
}
