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
        LeaderGym(const std::string& nom, const std::string& gymnase, const std::string& badge,
                const std::vector<std::string>& nomsPokemon);

        std::string getGymnase() const;
        std::string getBadge() const;
        /// @brief Leader interragit avec le joueur
        /// @param joueurActif 
        void interagir(joueur::Joueur* joueurActif) const;
};
}

#endif
