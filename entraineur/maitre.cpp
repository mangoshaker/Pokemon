#include "maitre.h"
#include "../pokemonLoader/pokemonLoader.h"
#include "../pokemon/pokemon.h"
#include "entraineur.h"
#include <iostream>

using namespace std;
using namespace pokemonLoader;
using namespace pokemon;
using namespace entraineur;
using namespace maitre; 

namespace maitre {

/**
 * @brief Constructeur de Maitre : initialise le nom + équipe Pokémon.
 * 
 * @param nom Nom du maître Pokémon
 * @param nomsPokemon Liste des noms de Pokémon pour constituer son équipe
 */
Maitre::Maitre(const string& nom, const vector<string>& nomsPokemon)
    : entraineur::Entraineur(nom) {

    vector<Pokemon*> base = PokemonLoader::chargerDepuisCSV();
    for (const string& nomRecherche : nomsPokemon) {
        for (Pokemon* p : base) {
            if (p->getNom() == nomRecherche) {
                //appliquer bonus de degats +25%
                p->setDegat(p->getDegat() * 1.25f);
                this->ajouterPokemon(p);
                break;
            }
        }
    }
}

/**
 * @brief Message d’interaction du Maître Pokémon
 * 
 * @return string Message de défi
 */
string Maitre::interagir() {
    return "Je suis le Maître Pokémon ultime. Prépare-toi à l’affrontement !";
}


} // namespace maitre
