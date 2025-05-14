#ifndef MAITRELOADER_H
#define MAITRELOADER_H

#include "../maitre.h"
#include <vector>
#include <string>

namespace maitreLoader {
    class MaitreLoader {
    public:
        /// @brief Charge tous les maîtres Pokémon depuis le fichier CSV 'maitres.csv'.
        /// @brief Chaque ligne doit contenir : Nom, [Pokemon1, ..., Pokemon6]
        /// @brief Les Pokémon sont recherchés dans la base principale (pokemon.csv).
        /// @return std::vector<maitre::Maitre*> Liste de pointeurs vers les objets Maitre créés.
        /// @throws std::runtime_error si le fichier est introuvable ou mal formé.
        static std::vector<maitre::Maitre*> chargerDepuisCSV(); 

        /// @brief Enregistre un maître dans le fichier 'maitres.csv'.
        /// @param maitre Référence vers un objet Maitre à enregistrer.
        /// @throws std::runtime_error si le fichier ne peut pas être ouvert en écriture.
        static void enregistrerDansCSV(const maitre::Maitre& maitre);  
    };
}

#endif

