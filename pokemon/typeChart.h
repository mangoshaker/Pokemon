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
    protected:
        std::map<std::pair<std::string, std::string>, float> tablemult;
        std::map<std::pair<std::string, std::string>, float> fillMap();
    private:
        void chargerTypeChart(const std::string& filename);
    };
}
#endif