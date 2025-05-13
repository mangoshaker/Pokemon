#ifndef MAITRELOADER_H
#define MAITRELOADER_H

#include "../maitre.h"
#include <vector>
#include <string>

namespace maitreLoader {
    class MaitreLoader {
    public:
        static std::vector<maitre::Maitre*> chargerDepuisCSV(); 
        static void enregistrerDansCSV(const maitre::Maitre& maitre);  
    };
}

#endif

