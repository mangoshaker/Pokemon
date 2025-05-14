#ifndef COMBAT_H
#define COMBAT_H
#include "../entraineur/entraineur.h"
#include "../pokemon/pokemon.h"
#include "../pokemon/typeChart.h"
#include <iostream> 
#include <vector>
#include <string>

using namespace entraineur;
using namespace typechart;
using namespace pokemon;

namespace combat{
    class Combat{
        public:
            Combat(Entraineur* Joueur, Entraineur* Adversaire);
            /// @brief Lance la partie
            /// @return Renvoie le gagnant
            Entraineur* start_partie();
            ~Combat();
        
        private:
            int tour;
            Entraineur* joueur;
            Entraineur* adversaire;
            TypeChart* mapMulti;                    
            std::vector <Pokemon*> eq_joue ;
            std::vector <Pokemon*> eq_adver ;
            /// @brief Simule l'attaque d'un pokémon, calcule les dégats engendrés et déduit le score final des HP du defenseur (0 si perdu);
            /// @param attaquant 
            /// @param defenseur 
            /// @param pos_HP_def position du HP du défenseur
            /// @param HP tableau des HP
            /// @return True quand il faut changer le pokemon du defenseur, false sinon
            bool combattre(Pokemon* attaquant, Pokemon* defenseur, int pos_HP_def, float HP[2]);
            /// @brief Simule le combat des pokémons
            /// @param ind_joue 
            /// @param ind_adver 
            /// @param HP 
            /// @return l'Entraineur gagnant
            Entraineur* tour_jeu(float HP[2]);
            /// @brief Détecte la fin du jeu
            /// @param HP 
            /// @param ind_joue 
            /// @param ind_adver 
            /// @return True si le jeu est fini, False sinon
            bool finJeu(float HP[2], int ind_joue, int ind_adver);
           
    };
}


#endif
