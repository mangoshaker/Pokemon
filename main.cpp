#include <iostream>
#include <string>
#include <vector>
#include "pokemon/pokemon.h"
#include "pokemon/typeChart.h"
#include "entraineur/entraineur.h"
#include "combat/combat.h"
#include "pokemonLoader/pokemonLoader.h"
#include "entraineur/joueur.h"
#include "entraineur/joueurLoader/joueurLoader.h"
#include "entraineur/leaderGym.h"
#include "entraineur/leaderLoader/leaderLoader.h"
#include "entraineur/maitreLoader/maitreLoader.h"
#include "entraineur/maitre.h"
#include "interaction/interaction.h"
#include "jeu/jeu.h"

using namespace interaction;
using namespace std;
using namespace pokemon;
using namespace typechart;
using namespace entraineur;
using namespace combat;
using namespace pokemonLoader;
using namespace joueur;
using namespace joueurLoader;
using namespace leaderGym;
using namespace leaderLoader;
using namespace leaderGym; 
using namespace maitre;
using namespace maitreLoader;
using namespace jeu;


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

    chlo->interagir() ;

    cout<<"1er pokemon : "<<chlo->getPokemonSelec()->getNom()<<endl;
    delete chlo; 
}

void testEntraineurCie(){
    try {
        // === 1. Charger les maîtres depuis le fichier CSV
        vector<Maitre*> maitres = MaitreLoader::chargerDepuisCSV();
        cout << "=== Maîtres Pokémon chargés ===" << endl;

        for (Maitre* m : maitres) {
            cout << "\nNom : " << m->getNom() << endl;
            m->interagir() ;

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

void afficherTousLesJoueurs(const vector<Joueur*>& joueurs) {
    for (const Joueur* j : joueurs) {
        cout << "Nom : " << j->getNom() << endl;
        cout << "Badges : ";
        for (const auto& [type, possede] : j->getBadges()) {
            cout << type << "=" << (possede ? "1" : "0") << "  ";
        }
        cout << "\n-----------------------------\n";
    }
}

bool testerEligibilitePourMaitre(const Joueur* joueur) {
    if (joueur->estPretPourAffronterMaitre()) {
        cout << "[V] " << joueur->getNom() << " peut affronter le Maître !" << endl;
        return true;
    } else {
        cout << "[X] " << joueur->getNom() << " n’a pas encore tous les badges." << endl;
        return false;
    }
}

void lancerCombatContreMaitre(Joueur* joueur, const vector<Maitre*>& maitres) {
    if (maitres.empty()) {
        cerr << "Aucun Maître disponible pour le combat." << endl;
        return;
    }

    Maitre* maitre = maitres[0];
    cout << "\n Début du combat entre " << joueur->getNom() << " et le Maître " << maitre->getNom() << " !" << endl;

    Combat combat(joueur, maitre);
    combat.start_partie();
}

void gererCombatFinalJoueurVsMaitre() {
    try {
        JoueurLoader jloader;
        vector<Joueur*> joueurs = jloader.getJoueurs();
        vector<Maitre*> maitres = MaitreLoader::chargerDepuisCSV();

        afficherTousLesJoueurs(joueurs);

        for (Joueur* j : joueurs) {
            if (j->getNom() == "Sacha" && testerEligibilitePourMaitre(j)) {
                lancerCombatContreMaitre(j, maitres);
            }
        }

    } catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
    }
}

/// @brief Test de l'interface Interaction
void testInteractions() {
    // --- Création du joueur avec 2 Pokémon ---
    vector<string> nomsJoueur = {"Pikachu", "Bulbizarre"};
    Joueur* joueur = new Joueur("Sacha", nomsJoueur);

    // --- Création du leader d'arène avec une équipe ---
    vector<string> nomsOndine = {"Carapuce", "Magicarpe"};
    LeaderGym* ondine = new LeaderGym("Ondine", "Cascade", "Azuria", nomsOndine);

    // --- Création du maître avec une équipe ---
    vector<string> nomsMaitre = {"Dracolosse", "Ronflex", "Alakazam"};
    Maitre* maitre = new Maitre("Lance", nomsMaitre);

    // --- Interactions avec les Pokémon du joueur ---
    cout << "\n[INTERACTIONS AVEC LES POKÉMON DU JOUEUR]" << endl;
    for (Pokemon* p : joueur->getEquipe()) {
        cout << "- ";
        p->interagir();
    }

    // --- Interactions avec les entraîneurs ---
    cout << "\n[INTERACTIONS AVEC LES ENTRAÎNEURS]" << endl;
    cout << "- Ondine : "; ondine->interagir(joueur);
    cout << "- Lance : ";   maitre->interagir();

    // --- Nettoyage ---
    delete joueur;
    delete ondine;
    delete maitre;
}

/// @brief tester le *1.25 pour les degats de pokemon de maitre
void testEntraineurCie2() {
    try {
        // === 1. Charger les maîtres depuis le fichier CSV
        vector<Maitre*> maitres = MaitreLoader::chargerDepuisCSV();
        cout << "=== Maîtres Pokémon chargés ===" << endl;

        for (Maitre* m : maitres) {
            cout << "\nNom : " << m->getNom() << endl;
            m->interagir();

            cout << "--- Équipe de " << m->getNom() << " ---" << endl;
            for (Pokemon* p : m->getEquipe()) {
                p->infoPokemon();
                cout << "Dégâts boostés : " << p->getDegat() << endl;
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
}


void testMenu(){
    Jeu jeu;
    jeu.StartJeu(); 
}

void Test(){
    system("chcp 65001 > nul"); // Active UTF-8 pour la console Windows
    //testPokemon();
    //testTypeChart();
    //testEntraineur(); 
    //testCombat();   
    //testEntraineurCie();
    //gererCombatFinalJoueurVsMaitre();
    //testMenu();
    //testInteractions(); 
}

int main() {
    system("chcp 65001 > nul");
    Jeu jeu;
    jeu.StartJeu();
    system("pause");
    return 0;
}
