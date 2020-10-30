#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <unistd.h>
#include <unordered_map>
#include <vector>
#include "player.hpp"
#include "portfolio.hpp"

extern std::vector<Player> players;
extern std::vector<Portfolio> portfolios;
// https://stackoverflow.com/questions/11072244/c-multiple-definitions-of-a-variable
// Player bank("Bank", (100000));

void option();
void viewBalance();
void makeObj();
// https://docs.microsoft.com/en-us/cpp/cpp/extern-cpp?view=msvc-160

#endif