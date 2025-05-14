#include "joueur.h"
#include <iostream>
#include <string>
#include "../pokemonLoader/pokemonLoader.h"

using namespace std;
using namespace joueur;
using namespace pokemonLoader;


//Constructeur
Joueur::Joueur(const string& nom, const vector<string>& nomPokemon)
    : Entraineur(nom), nb_badges(0), nb_gagne(0), nb_perdu(0) {
        //charger la base de tous les pokemon connus
        vector<pokemon::Pokemon*> base = PokemonLoader::chargerDepuisCSV();
        for (const string& nomRecherche : nomPokemon){
            for (pokemon::Pokemon* p : base) {
                if(p->getNom() == nomRecherche) {
                    ajouterPokemon(p);
                    break; 
                }
            }
        }
    }

//Getters
int Joueur::getNbBadges() const {return nb_badges; }
int Joueur::getNbGagne() const {return nb_gagne;}
int Joueur::getNbPerdu() const {return nb_perdu;}

//Setters
void Joueur::ajouterBadges() { nb_badges++; }
void Joueur::ajouterGagne() { nb_gagne++ ; }
void Joueur::ajouterPerdu() { nb_perdu++;}





