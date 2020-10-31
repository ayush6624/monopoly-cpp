#ifndef MONOPOLY_constants_hpp
#define MONOPOLY_constants_hpp
#include <vector>
// constexpr is available at compile time rather than run time

namespace constants
{
    constexpr int STARTING_MONEY = 10000;
    constexpr int JAIL_MONEY = 100;
    constexpr int PASS_GO = 100;
    constexpr int NUMBER_OF_PLAYERS = 6;
    constexpr double RENT_PERCENTAGE = 0.1;
    constexpr double MORTGAGE_PERCENT = 0.15;
    // vector<std::string> status = {"PASSGO", "JAIL,"
    // "RENT,"
    // "BUYING",
    //   "BUILDING", "MORTGAGE"};
} // namespace constants

#endif
