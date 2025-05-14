#ifndef MAITRE_H
#define MAITRE_H

#include "entraineur.h"
#include "../pokemon/pokemon.h"
#include <string>
#include <vector>

namespace maitre {

class Maitre : public entraineur::Entraineur {
public:
    /// @brief Constructeur de Maitre : initialise le nom + équipe Pokémon.
    /// @param nom Nom du maître Pokémon
    /// @param nomsPokemon Liste des noms de Pokémon pour constituer son équipe
    Maitre(const std::string& nom, const std::vector<std::string>& nomsPokemon);

    //ajout de l'interaction (message de defi)
    /// @brief affichage pour annoncer le maitre
    void interagir() override;

    
};

}

#endif
