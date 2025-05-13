#ifndef LEADERLOADER_H
#define LEADERLOADER_H

#include "../leaderGym.h"
#include <vector>
#include <string>

namespace leaderLoader{
    class LeaderLoader {
    public:
        static std::vector<leaderGym::LeaderGym*> chargerDepuisCSV();
        static void enregistrerDansCSV(const leaderGym::LeaderGym& leader);
    };

}

#endif
