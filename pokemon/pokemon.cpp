#include "pokemon.h"
#include <iostream>
#include <string>
using namespace std;

Pokemon(string Nom, int hp, string Attaque, int Degat, string type1, string type2=""){
    nom = Nom;
    HP = hp;
    attaque = Attaque;
    degat = Degat;
    types.push_back(type1);
    if(type2!="") types.push_back(type2);
}

virtual void attaquer(Pokemon* cible)=0;

virtual string interagir(){
    cout<<nom.substr(0,4)+nom.substr(0,4)<<", je suis "<<nom<<"!"<<endl;
}