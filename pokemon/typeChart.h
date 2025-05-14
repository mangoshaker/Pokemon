#ifndef TYPECHART_H
#define TYPECHART_H

#include <iostream>
#include <string>
#include <map>
#include "pokemon.h"

namespace typechart{
    class TypeChart{
    public : 
        TypeChart();
        /// @brief Renvoie le multiplicateur de dégats en fonction des types du pokemon attaquant et ceux du defenseur
        /// @param attaquant 
        /// @param defenseur 
        /// @return 
        float getMult(pokemon::Pokemon* attaquant, pokemon::Pokemon* defenseur);
        /// @brief Affiche TypeChart
        void afficherTypeChart();
    private:
        /// @brief Remplie la map des faiblesses/résistances
        /// @param filename 
        void creationTypeChart(const std::string& filename);
        std::map<std::pair<std::string, std::string>, float> tablemult;
        /// @brief renvoie le multiplicateur associé à deux types
        /// @param type_att 
        /// @param type_def 
        /// @return 
        float getMultIndiv(const std::string& type_att,const  std::string& type_def);
    };
}
#endif