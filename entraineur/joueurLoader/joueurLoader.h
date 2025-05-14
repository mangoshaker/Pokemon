#ifndef JOUEURLOADER_H
#define JOUEURLOADER_H

#include "../joueur.h"
#include <vector>
#include <string>
using namespace joueur;

namespace joueurLoader{
    class JoueurLoader {
        public:
            JoueurLoader();
            /// @brief Accède aux joueurs
            /// @return vecteur : joueurs
            const std::vector<Joueur*>& getJoueurs()const;
            /// @brief Création d'un joueur
            /// @param nouveau Joueur
            void ajouterJoueur(Joueur* nouveau) ;
        
        private:
            // Charge tous les joueurs depuis joueur.csv
            static std::vector<joueur::Joueur*> chargerDepuisCSV();            
            // Enregistre un joueur à la fin du fichier joueur.csv
            static void enregistrerDansCSV(const joueur::Joueur& joueur);
            std::vector<Joueur*> joueurs;
        };
}


#endif
