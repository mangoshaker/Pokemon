#include <iostream>
#include <string>
#include "pokemon/pokemon.h"
#include "entraineur/entraineur.h"

using namespace std;
using namespace pokemon;
using namespace Entraineur;

void testPokemon() {
    Pokemon pikachu("Pikachu", 35, "Eclair", 55, "Electrik");
    pikachu.infoPokemon();
}

void testEntraineur()
{
    pokemon::Pokemon* pikachu = new pokemon::Pokemon("Pikachu", 35, "Eclair", 55, "Electrik");
    Entraineur::Entraineur* chlo = new Entraineur::Entraineur("Chlo");

    chlo->ajouterPokemon(pikachu);

    cout<< chlo->interagir() <<endl;

    cout<<"1er pokemon : "<<chlo->getPokemonSelec()->getNom()<<endl;
    delete chlo; 
}

int main() {
    system("chcp 65001 > nul"); //active UTF-8
    testPokemon();
    testEntraineur(); 
    system("pause"); 
    return 0;
}
