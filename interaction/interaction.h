#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>

namespace interaction{
    class Interaction {
        public:
            /// @brief Fait interagir un élément du jeu
            virtual std::string interagir() = 0;            
            virtual ~Interagir() = default;
        };    
}
#endif
