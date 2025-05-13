#include "leaderGym.h"
#include "../pokemonLoader/pokemonLoader.h"
#include "../pokemon/pokemon.h"
#include "entraineur.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using namespace entraineur;
using namespace pokemonLoader;
using namespace leaderGym; 
using namespace pokemon;


/**
 * @brief Constructeur de la classe LeaderGym.
 * 
 * Initialise un leader avec son nom, gymnase, badge, et son équipe de Pokémon.
 * Les Pokémon sont recherchés dans la base complète chargée depuis pokemon.csv.
 * 
 * @param nom Nom du leader
 * @param gymnase Nom de l'arène qu'il dirige
 * @param badge Nom du badge que le leader remet
 * @param nomsPokemon Liste des noms de Pokémon qui composent l'équipe
 */
leaderGym::LeaderGym::LeaderGym(const string& nom, const string& gymnase, const string& badge, const vector<string>& nomsPokemon)
    : entraineur::Entraineur(nom), gymnase(gymnase), badge(badge) {

    vector<pokemon::Pokemon*> base = PokemonLoader::chargerDepuisCSV();
    for (const string& nomRecherche : nomsPokemon) {
        for (pokemon::Pokemon* p : base) {
            if (p->getNom() == nomRecherche) {
                this->ajouterPokemon(p);
                break;
            }
        }
    }
}


/**
 * @brief Renvoie le nom du gymnase du leader.
 * 
 * @return string nom du gymnase
 */
string LeaderGym::getGymnase() const { return gymnase; }


/**
 * @brief Renvoie le nom du badge remis par le leader.
 * 
 * @return string nom du badge
 */
string LeaderGym::getBadge() const { return badge; }


/**
 * @brief Message personnalisé d’interaction avec le leader.
 * 
 * Simule un message typique de défi entre joueur et leader d’arène.
 * 
 * @return string Message d'interaction
 */
string leaderGym::LeaderGym::interagir() {
    return "Je suis le leader de l'arène " + gymnase + " ! Gagne et remporte le badge " + badge + " !";
}
