#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include "constants.hpp"

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
    Player(std::string s);
    int money = 20000;
    void passGo();
    void creditMoney(int money, Player &player);
    void debitMoney(int money, Player &player);
    void jailRescue();
    void rent();
    void buildHouse();
    void showBalance();
    void viewBalance();
};

// bank.money;

#endif