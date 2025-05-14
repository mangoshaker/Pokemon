#include "combat.h"
#include "../entraineur/entraineur.h"
#include "../pokemon/pokemon.h"
#include "../pokemon/typeChart.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace entraineur;
using namespace pokemon;
using namespace combat;

Combat::Combat(Entraineur* Joueur, Entraineur* Adversaire){
    this-> tour = 0;
    this-> joueur = Joueur;
    this-> adversaire= Adversaire;
    this-> mapMulti = new TypeChart();    
    this->eq_joue = Joueur->getEquipe();
    this->eq_adver = Adversaire->getEquipe();
}

/// @brief Lance la partie
Entraineur* Combat::start_partie(){
    int compteur = 0;
    cout << "Debut du combat entre "<< joueur->getNom()<< " et "<< adversaire->getNom()<< endl;
    
    float HP[2] = {static_cast<float>(eq_joue[0]->getHP()), static_cast<float>(eq_adver[0]->getHP())};    //score joueur , score adversaire

    Entraineur* gagnant = tour_jeu(HP);

    cout <<gagnant->getNom()<<" a gagne la partie !"<<endl;
    return gagnant;
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

/// @brief Détecte la fin du jeu
/// @param HP 
/// @param ind_joue 
/// @param ind_adver 
/// @return True si le jeu est fini, False sinon
bool Combat::finJeu(float HP[2], int ind_joue, int ind_adver) {
    return (HP[0] <= 0) || (HP[1] <= 0 );
}


/// @brief Simule le combat des pokémons
/// @param ind_joue 
/// @param ind_adver 
/// @param HP 
/// @return l'Entraineur gagnant
Entraineur* Combat::tour_jeu(float HP[2]){
    //initialisation
    int ind_joue = 0;
    int ind_adver = 0;
    int tour_count = 1;

    //jeu
    while(!finJeu(HP,ind_joue,ind_adver)){
        cout << "\n===== TOUR " << tour_count << " =====" << endl;
        bool perdu = false;

        if(this->tour == 0 ){ //Joueur qui attaque
            cout<<"[Joueur] ";
            eq_joue[ind_joue]->attaquer(eq_adver[ind_adver]);
            perdu=combattre(eq_joue[ind_joue],eq_adver[ind_adver],1 , HP);
            this->tour=1;
        } 
        else {  //Adversaire qui attaque
            cout<<"[Rival] ";
            eq_adver[ind_adver]->attaquer(eq_joue[ind_joue]);
            perdu=combattre(eq_adver[ind_adver],eq_joue[ind_joue],0,HP);
            this->tour=0;
        }

        if (perdu){
            if (this->tour==1 && ind_adver<eq_adver.size()-1) {
                ind_adver++;
                HP[1]=eq_adver[ind_adver]->getHP();
                cout<<"-> Nouveau Pokemon de [Rival] : "<<eq_adver[ind_adver]->getNom() << " entre en jeu !" <<endl;
            }
            else if (this->tour==0 && ind_joue +1<eq_joue.size()-1) {
                ind_joue++;
                HP[0]=eq_joue[ind_joue]->getHP();
                cout<<"-> Nouveau Pokemon de [Joueur] : " << eq_joue[ind_joue]->getNom() << " entre en jeu !" << endl;
            }
        }
        tour_count++; 
    }
    
    //renvoi du gagnant de la partie
    cout << "\n [VICTOIRE] " << (HP[0] <= 0 ? adversaire->getNom() : joueur->getNom()) << " a gagné le combat !" << endl;
    if(HP[0]<=0) return adversaire;
    else return joueur;
}

/// @brief Destructeur
Combat::~Combat() {
    delete mapMulti;
}


