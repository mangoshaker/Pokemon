#ifndef LEADERLOADER_H
#define LEADERLOADER_H

#include "../leaderGym.h"
#include <vector>
#include <string>

namespace leaderLoader{
    class LeaderLoader {
    public:
        /// @brief Charge tous les leaders depuis le fichier CSV 'leaders.csv'.
        /// @return std::vector<LeaderGym*> Liste de pointeurs vers les objets LeaderGym créés.
        static std::vector<leaderGym::LeaderGym*> chargerDepuisCSV();

        /// @brief Enregistre un nouveau leader dans le fichier 'leaders.csv'.
        /// @param leader Référence vers un objet LeaderGym à enregistrer.
        static void enregistrerDansCSV(const leaderGym::LeaderGym& leader);
    };

}

#endif
