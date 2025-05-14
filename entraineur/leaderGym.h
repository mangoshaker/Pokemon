#ifndef LEADERGYM_H
#define LEADERGYM_H

#include "entraineur.h"
#include "joueur.h"
#include <string>
#include <vector>

namespace leaderGym {
    class LeaderGym : public entraineur::Entraineur {
    private:
        std::string gymnase;
        std::string badge;

    public:
        /// @brief Constructeur de la classe LeaderGym.
        /// Initialise un leader avec son nom, gymnase, badge, et son équipe de Pokémon.
        /// Les Pokémon sont recherchés dans la base complète chargée depuis pokemon.csv.
        /// @param nom Nom du leader
        /// @param gymnase Nom de l'arène qu'il dirige
        /// @param badge Nom du badge que le leader remet
        /// @param nomsPokemon Liste des noms de Pokémon qui composent l'équipe
        LeaderGym(const std::string& nom, const std::string& gymnase, const std::string& badge,
                const std::vector<std::string>& nomsPokemon);
        
        // getters
        /// @brief Renvoie le nom du gymnase du leader.
        /// @return string nom du gymnase
        std::string getGymnase() const;

        /// @brief Renvoie le nom du badge remis par le leader.
        /// @return string nom du badge 
        std::string getBadge() const;

        

        /// @brief Leader interragit avec le joueur
        /// @param joueurActif 
        void interagir(joueur::Joueur* joueurActif) const;
};
}

#endif
