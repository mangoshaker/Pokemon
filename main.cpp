#include <iostream>
#include "pokemon/pokemon.h"
#include "pokemon/typeChart.h"

using namespace std;
using namespace pokemon;
using namespace typechart;

void testPokemon() {
    Pokemon pikachu("Pikachu", 35, "Éclair", 55, "Électrik");
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

int main() {
    testPokemon();
    //testTypeChart();
    system("pause"); 
    return 0;
}
