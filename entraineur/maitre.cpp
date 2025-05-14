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
                //creer une copie de pokemon (constructeur de copie)
                Pokemon* clone = new Pokemon(*p);
                
                //test debugging 
                //float baseDegat = clone->getDegat();
                
                //appliquer bonus de degats +25%
                clone->setDegat(clone->getDegat() * 1.25f);

                //test debugging
                //cout << "DEBUG: " << clone->getNom() << " base degat = " << baseDegat 
                //<< ", boosté = " << clone->getDegat() << endl;

                this->ajouterPokemon(clone);
                break;
            }
        }
    }
}

void Maitre::interagir() {
    cout << getNom() << " : Je suis le Maitre Pokemon !" << endl;
}





