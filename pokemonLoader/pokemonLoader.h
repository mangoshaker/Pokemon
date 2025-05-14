#ifndef POKEMONLOADER_H
#define POKEMONLOADER_H

#include "../pokemon/pokemon.h"
#include <vector>
#include <string>

namespace pokemonLoader{
    class PokemonLoader {
    public:
        /// @brief charge tous les pokemons depuis le fichier pokemon.csv et les retournes sous fore de pointeurs dans un vecteur
        /// @return std::vector<Pokemon*> contenant tous les pokemons charges
        static std::vector<pokemon::Pokemon*> chargerDepuisCSV();
    };
}

#endif