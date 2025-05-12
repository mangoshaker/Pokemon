#ifndef COMBAT_H
#define COMBAT_H
#include "entraineur.h"
//#include "pokemon.h"
#include "typeChart.h"
#include <iostream> 
#include <vector>
#include <string>

using namespace entraineur;
using namespace typechart;
//using namespace pokemon;

namespace combat{
    class Combat{
        public:
            void start_partie();
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
            bool Combat::combattre(Pokemon* attaquant, Pokemon* defenseur, int pos_HP_def, float[2] HP);
            /// @brief Simule le combat des pokémons
            /// @param ind_joue 
            /// @param ind_adver 
            /// @param HP 
            /// @return l'Entraineur gagnant
            Entraineur* Combat::tour(int ind_joue, int ind_adver, float[2] HP);
    };
}


#endif
