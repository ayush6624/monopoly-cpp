#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>

class Player
{
private:
    std::string username;
    std::string password;

public:
    enum Status
    {
        ALIVE,
        INJAIL,
        DEAD
    };

    int money;
    void passGo();
    void creditMoney(int money, Player player);
    void debitMoney(int money, Player player);
};

#endif