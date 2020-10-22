#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include "constants.hpp"
#include "file.hpp"
#include "property.hpp"

class Player
{
private:
    std::string username;
    std::string password;
    int money = 20000; // currentBankBalance
public:
    enum Status
    {
        ALIVE,
        IN_JAIL,
        DEAD
    };
    Player(std::string s);
    void passGo();
    void creditMoney(int money, Player &player);
    void debitMoney(int money, Player &player);
    void jailRescue();
    void rent();
    void buyProperty(Player &P);
    void buildHouse();
    
    void showBalance();
};

// bank.money;
// parent - trasaction(credit, debit) , child - Operation(jail, rent, buy)
// player class <----friend----> operation class => retrive 2 things- username + bankbalance from Player
#endif