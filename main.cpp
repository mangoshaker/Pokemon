#include <iostream>
#include "pokemon/pokemon.h"

using namespace std;
using namespace pokemon;

void testPokemon() {
    Pokemon pikachu("Pikachu", 35, "Éclair", 55, "Électrik");
    pikachu.infoPokemon();
}

int main() {
    testPokemon();
    system("pause"); 
    return 0;
}
