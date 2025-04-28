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
    map.afficherTypeChart();
}

int main() {
    //testPokemon();
    //testTypeChart();
    system("pause"); 
    return 0;
}
