#ifndef JOUEURLOADER_H
#define JOUEURLOADER_H

#include "../joueur.h"
#include <vector>
#include <string>

namespace joueurLoader{
    class JoueurLoader {
        public:
            // Charge tous les joueurs depuis joueur.csv
            static std::vector<joueur::Joueur*> chargerDepuisCSV();
        
            // Enregistre un joueur à la fin du fichier joueur.csv
            static void enregistrerDansCSV(const joueur::Joueur& joueur);
        };
}


#endif
