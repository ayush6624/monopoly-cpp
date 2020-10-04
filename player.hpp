#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
// #include "game.hpp"

class Player
{
private:
    std::string username;
    std::string password;

public:
    enum Status
    {
        ALIVE,
        IN_JAIL,
        DEAD
    };
    Player() {}

    int money = 20000;
    void passGo();
    void creditMoney(int money, Player &player);
    void debitMoney(int money, Player &player);
    void jailRescue(Player &p);
    void showBalance();
};

// bank.money;

#endif