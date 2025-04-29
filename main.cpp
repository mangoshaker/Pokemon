#include <iostream>
#include "pokemon/pokemon.h"

using namespace std;
using namespace pokemon;

void testPokemon() {
    Pokemon pikachu("Pikachu", 35, "Eclair", 55, "Electrik");
    pikachu.infoPokemon();
}

int main() {
    testPokemon();
    system("pause"); 
    return 0;
}
