#ifndef MAITRE_H
#define MAITRE_H

#include "entraineur.h"
#include "../pokemon/pokemon.h"
#include <string>
#include <vector>

namespace maitre {

class Maitre : public entraineur::Entraineur {
public:
    Maitre(const std::string& nom, const std::vector<std::string>& nomsPokemon);

    std::string interagir() override;

    
};

}

#endif
