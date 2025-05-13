#include <iostream>
#include <string>
#include "pokemon/pokemon.h"
#include "pokemon/typeChart.h"
#include "entraineur/entraineur.h"
#include "pokemonLoader/pokemonLoader.h"
#include "entraineur/joueur.h"
#include "entraineur/joueurLoader/joueurLoader.h"
#include "entraineur/leaderGym.h"
#include "entraineur/leaderLoader/leaderLoader.h"
#include "entraineur/maitreLoader/maitreLoader.h"
#include "entraineur/maitre.h"

using namespace std;
using namespace pokemon;
using namespace typechart;
using namespace entraineur;
using namespace pokemonLoader;
using namespace joueur;
using namespace joueurLoader;
using namespace leaderGym;
using namespace leaderLoader;
using namespace leaderGym; 
using namespace maitre;
using namespace maitreLoader;


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
    Pokemon* pikachu = new Pokemon("Pikachu", 35, "Eclair", 55, "Electrik");
    Entraineur* chlo = new Entraineur("Chlo");

    chlo->ajouterPokemon(pikachu);

    cout<< chlo->interagir() <<endl;

    cout<<"1er pokemon : "<<chlo->getPokemonSelec()->getNom()<<endl;
    delete chlo; 
}

int main() {
    //testPokemon();
    //testTypeChart();
    //testEntraineur(); 
    //system("pause");
    try {
        // === 1. Charger les maîtres depuis le fichier CSV
        vector<Maitre*> maitres = MaitreLoader::chargerDepuisCSV();
        cout << "=== Maîtres Pokémon chargés ===" << endl;

        for (Maitre* m : maitres) {
            cout << "\nNom : " << m->getNom() << endl;
            cout << m->interagir() << endl;

            cout << "--- Équipe de " << m->getNom() << " ---" << endl;
            for (Pokemon* p : m->getEquipe()) {
                p->infoPokemon();
                cout << "------------------------" << endl;
            }

            // ✅ 2. Test de l'attaque du Pokémon sélectionné
            Pokemon* cible = new Pokemon("Pikachu", 35, "Éclair", 55, "Electrik");
            cout << "\n[TEST] " << m->getNom() << " utilise son premier Pokémon pour attaquer :" << endl;
            m->getPokemonSelec()->attaquer(cible);
            delete cible;
        }

    } catch (const exception& e) {
        cerr << "\nErreur pendant l'exécution : " << e.what() << endl;
    }

    system("pause");
    return 0;
}
