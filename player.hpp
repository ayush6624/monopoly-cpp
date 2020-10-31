#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include "constants.hpp"
#include "file.hpp"
#include "property.hpp"
#include "account.hpp"
#include "portfolio.hpp"
// #include "game.hpp"

class Player
{
private:
    std::string password;
    // int money = 20000; // currentBankBalance
    int loanValue;
    Account acc;
    Portfolio portfolio;

public:
    std::string username;
    enum Status
    {
        ALIVE,
        IN_JAIL,
        DEAD
    };
    // initializer list
    Player(const std::string &name, const Account &a, const Portfolio &p)
        : username{name}, acc{a}, portfolio{p}
    {
        // std::cout << "Constructor for player " << this->username << "\n";
    }
    ~Player()
    {
        // std::cout << "Destructor for player " << this->username << "\n";
    }

    void passGo();
    void creditMoney(int money, Player &player);
    void debitMoney(int money, Player &player);
    void jailRescue();
    void rent();
    void mortgage();
    void buyProperty();
    void buildHouse();
    int showBalance();
    void loan();
    // friend int credit(int money, Player &player);
};

// Player bank("Bank", (100000));
// bank.money;
// parent - trasaction(credit, debit) , child - Operation(jail, rent, buy)
// player class <----friend----> operation class => retrive 2 things- username + bankbalance from Player
#endif