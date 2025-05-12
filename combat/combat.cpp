#include "combat.h"
#include "entraineur.h"
#include "pokemon.h"
#include "typeChart.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace entraineur;
using namespace pokemon;

Combat::Combat(Entraineur* Joueur, Entraineur* Adversaire){
    this-> tour = 0;
    this-> joueur = Joueur;
    this-> adversaire= Adversaire;
    this-> mapMulti = new TypeChart();    
    this->eq_joue = Joueur->getEquipe();
    this->eq_adver = Adversaire->getEquipe();
}

/// @brief Lance la partie
void Combat::start_partie(){
    int compteur = 0;
    cout << "Début du combat entre "<< joueur->getNom()<< " et "<< adversaire->getNom()<< endl;
    
    float HP[2] = {eq_joue[0]->getHP(),eq_adver[0]->getHP()};    //score joueur , score adversaire

    Entraineur* gagnant = tour(HP);

    cout <<gagnant->getNom<<" a gagné la partie !"<<endl;

}

/// @brief Simule l'attaque d'un pokémon, calcule les dégats engendrés et déduit le score final des HP du defenseur (0 si perdu);
/// @param attaquant 
/// @param defenseur 
/// @param pos_HP_def position du HP du défenseur
/// @param HP tableau des HP
/// @return True quand il faut changer le pokemon du defenseur, false sinon
bool Combat::combattre(Pokemon* attaquant, Pokemon* defenseur, int pos_HP_def, float HP[2]){
    float degat = attaquant->getDegat() * mapMulti->getMult(attaquant, defenseur); 
    HP[pos_HP_def]-=degat;
    cout << "Il inflige " << degat << " degats." << endl;
    cout << "HP restants : " << max(0.0f, HP[pos_HP_def]) << endl;

    if (HP[pos_HP_def]<=0) {
        cout << defenseur->getNom() << " est K.O. !" << endl;
        HP[pos_HP_def]=0; //réinitialise le score de l'adversaire si perdu
        return true;
    }
    else return false;
}

/// @brief Simule le combat des pokémons
/// @param ind_joue 
/// @param ind_adver 
/// @param HP 
/// @return l'Entraineur gagnant
Entraineur* Combat::tour(float HP[2]){
    //initialisation
    int ind_joue = 0;
    int ind_adver = 0;

    //jeu
    while(!finJeu(HP,ind_joue,ind_adver)){
        bool perdu = false;
        if(this->tour == 0 ){ //Joueur qui attaque
            eq_joue[ind_joue]->attaquer(eq_adver[ind_adver]);
            perdu=combattre(eq_joue[ind_joue],eq_adver[ind_adver],1 , HP);
            this->tour=1;
        } 
        else {  //Adversaire qui attaque
            eq_adver[ind_adver]->attaquer(eq_joue[ind_joue]);
            perdu=combattre(eq_adver[ind_adver],eq_joue[ind_joue],0,HP);
            this->tour=0;
        }
        if (perdu){
            if (this->tour==1 && ind_adver<5) {
                ind_adver++;
                HP[1]=eq_adver[ind_adver]->getHP();
            }
            else if (tour==0 && ind_joue <5) {
                ind_joue++;
                HP[0]=eq_joue[ind_joue]->getHP();
            }
        }
    }
    
    //renvoi du gagnant de la partie
    if(HP[0]<=0) return adversaire;
    else return joueur;
}

