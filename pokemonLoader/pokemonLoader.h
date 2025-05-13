#ifndef POKEMONLOADER_H
#define POKEMONLOADER_H

#include "../pokemon/pokemon.h"
#include <vector>
#include <string>

namespace pokemonLoader{
    class PokemonLoader {
    public:
        static std::vector<pokemon::Pokemon*> chargerDepuisCSV();
    };
}

#endif