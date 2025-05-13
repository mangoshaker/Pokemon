#include <iostream>
#include <string>
#include <vector>
#include "pokemon/pokemon.h"
#include "pokemon/typeChart.h"
#include "entraineur/entraineur.h"
#include "combat/combat.h"

using namespace std;
using namespace pokemon;
using namespace typechart;
using namespace entraineur;
using namespace combat;

/// @brief Teste la classe Pokemon
void testPokemon() {
    Pokemon pikachu("Pikachu", 35, "Eclair", 55, "Electrik");
    pikachu.infoPokemon();
}

/// @brief Teste la classe TypeChart
void testTypeChart(){
    TypeChart map;
    //map.afficherTypeChart();
    //cout<<map.getMultIndiv("Fée","Feu")<<endl;

    Pokemon salameche("Salamèche",39,"Flammèche",70,"Feu","");
    Pokemon carapuce("Carapuce",44,"Pistolet à O",65,"Eau","");

    //cout<<map.getMult(&carapuce, &salameche)<<endl;
    //cout<<map.getMult(&salameche,&carapuce)<<endl;
}

/// @brief Teste la classe Entraineur
void testEntraineur()
{
    Pokemon* pikachu = new Pokemon("Pikachu", 35, "Eclair", 55, "Electrik");
    Entraineur* chlo = new Entraineur("Chlo");

    chlo->ajouterPokemon(pikachu);

    cout<< chlo->interagir() <<endl;

    cout<<"1er pokemon : "<<chlo->getPokemonSelec()->getNom()<<endl;
    delete chlo; 
}

/// @brief Test de la classe Combat
void testCombat() {
    // Création des Pokémon pour le joueur
    Pokemon* p1 = new Pokemon("Pikachu", 35, "Éclair", 55, "Electrik");
    Pokemon* p2 = new Pokemon("Carapuce", 44, "Pistolet à O", 65, "Eau");
    Pokemon* p3 = new Pokemon("Salameche", 39, "Flammèche", 70, "Feu");
    Pokemon* p4 = new Pokemon("Bulbizarre", 45, "Fouet Lianes", 60, "Plante", "Poison");
    Pokemon* p5 = new Pokemon("Roucool", 40, "Cru-Ailes", 50, "Vol");
    Pokemon* p6 = new Pokemon("Rattata", 30, "Charge", 40, "Normal");

    // Création des Pokémon pour le rival
    Pokemon* a1 = new Pokemon("Nosferapti", 40, "Ultrason", 45, "Poison", "Vol");
    Pokemon* a2 = new Pokemon("Fantominus", 35, "Léchouille", 60, "Spectre", "Poison");
    Pokemon* a3 = new Pokemon("Onix", 45, "Jet-Pierres", 70, "Roche", "Sol");
    Pokemon* a4 = new Pokemon("Draco", 52, "Draco-Rage", 80, "Dragon");
    Pokemon* a5 = new Pokemon("Abo", 38, "Morsure", 60, "Poison");
    Pokemon* a6 = new Pokemon("Magicarpe", 20, "Trempette", 0, "Eau");

    Entraineur* joueur = new Entraineur("Joueur");
    Entraineur* rival = new Entraineur("Rival");

    // Ajout aux équipes
    joueur->ajouterPokemon(p1);
    joueur->ajouterPokemon(p2);
    joueur->ajouterPokemon(p3);
    joueur->ajouterPokemon(p4);
    joueur->ajouterPokemon(p5);
    joueur->ajouterPokemon(p6);

    rival->ajouterPokemon(a1);
    rival->ajouterPokemon(a2);
    rival->ajouterPokemon(a3);
    rival->ajouterPokemon(a4);
    rival->ajouterPokemon(a5);
    rival->ajouterPokemon(a6);

    // Combat
    Combat combat(joueur, rival);
    combat.start_partie();

    // Libération mémoire
    delete joueur;
    delete rival;

}



int main() {
    //testPokemon();
    //testTypeChart();
    //testEntraineur(); 
    testCombat();
    system("pause"); 
    return 0;
}
