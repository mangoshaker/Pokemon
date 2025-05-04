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
        float getMult(pokemon::Pokemon* attaquant, pokemon::Pokemon* defenseur);
        void afficherTypeChart();
    private:
        void creationTypeChart(const std::string& filename);
        std::map<std::pair<std::string, std::string>, float> tablemult;
        float getMultIndiv(const std::string& type_att,const  std::string& type_def);
    };
}
#endif