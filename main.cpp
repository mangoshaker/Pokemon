#include <iostream>
#include <string>
#include "pokemon/pokemon.h"
#include "pokemon/typeChart.h"
#include "entraineur/entraineur.h"

using namespace std;
using namespace pokemon;
using namespace typechart;
using namespace Entraineur;

void testPokemon() {
    Pokemon pikachu("Pikachu", 35, "Eclair", 55, "Electrik");
    pikachu.infoPokemon();
}

void testTypeChart(){
    TypeChart map;
    //map.afficherTypeChart();
    //cout<<map.getMultIndiv("Fée","Feu")<<endl;

    Pokemon salameche("Salamèche",39,"Flammèche",70,"Feu","");
    Pokemon carapuce("Carapuce",44,"Pistolet à O",65,"Eau","");

    //cout<<map.getMult(&carapuce, &salameche)<<endl;
    //cout<<map.getMult(&salameche,&carapuce)<<endl;
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
    //testTypeChart();
    testEntraineur(); 
    system("pause"); 
    return 0;
}
