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
            /// @brief Charge tous les joueurs depuis joueur.csv
            /// @return 
            static std::vector<joueur::Joueur*> chargerDepuisCSV();            
            // Enregistre un joueur à la fin du fichier joueur.csv

            /// @brief ajoute un joueur a joueur.csv
            /// @param joueur 
            static void enregistrerDansCSV(const joueur::Joueur& joueur);

            /// @brief  vectors de joueur pour le stockage
            std::vector<Joueur*> joueurs;
        };
}


#endif
