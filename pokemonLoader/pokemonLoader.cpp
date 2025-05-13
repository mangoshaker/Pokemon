#include "pokemonLoader.h"
#include "../pokemon/pokemon.h"
#include <fstream> // pour lire le fichier csv
#include <sstream> // pour decouper les lignes lues 
#include <iostream> // pour afficher messages d'erreur
#include <stdexcept> // pour throw des exceptions

using namespace std;
using namespace pokemon;
using namespace pokemonLoader;

/** 
* @brief charge tous les pokemons depuis le fichier pokemon.csv 
* et les retournes sous fore de pointeurs dans un vecteur
* @return std::vector<Pokemon*> contenant tous les pokemons charges
*/
vector<Pokemon*> PokemonLoader::chargerDepuisCSV() {
    vector<Pokemon*> pokemons;
    ifstream fichier("pokemon/Ressources/pokemon.csv"); // ouvrir le fichier dans le meme dossier que l'executable

    if(!fichier.is_open()){
        throw runtime_error("Erreur : impossible d'ouvrir le fichier.");
    }

    string ligne;
    getline(fichier, ligne); //Ignorer l'entete (= nom de chaque colonne)

    while (getline(fichier, ligne)) { //lire ligne par ligne
        stringstream ss(ligne); // decoupage de ligne en plusieurs morceau
        string nom, type1, type2, hpStr, attaque, degatStr;

        try { //lecture de chaque champ jusqu'a une , 
            getline(ss, nom, ','); 
            getline(ss, type1, ',');
            getline(ss, type2, ',');
            getline(ss, hpStr, ',');
            getline(ss, attaque, ',');
            getline(ss, degatStr, ',');
            
            //convertir string -> ligne
            int hp = stoi(hpStr);
            int degats = stoi(degatStr);

            //stockage des pokemons dans le vector
            Pokemon* p = new Pokemon(nom, hp, attaque, degats, type1, type2 );
            pokemons.push_back(p);
        } catch (const exception& e){
            cerr << "Erreur ligne : " <<ligne<<endl;
            cerr << "Exception : " <<e.what() << endl;
        }
    }
    fichier.close();
    return pokemons; 

}