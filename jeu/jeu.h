#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <vector>
#include "../entraineur/entraineur.h"
#include "../pokemon/pokemon.h"
#include "../pokemon/typeChart.h"
#include "../combat/combat.h"
#include "../entraineur/joueurLoader/joueurLoader.h"
#include "../entraineur/joueur.h"

using namespace joueurLoader;
using namespace joueur;

namespace jeu {
    class Jeu {
    public:
        Jeu();

        /// @brief Affiche tous les joueurs
        /// @return True s'il y a des joueurs, False sinon
        bool Aff_Joueurs();
        /// @brief Gère le menu et l'affichage console du jeu
        void Jeu::Menu()

    private:
        std::vector<Joueur*> joueurs;
    };
}  // namespace jeu

#endif
