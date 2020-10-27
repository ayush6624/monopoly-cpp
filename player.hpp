#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include "constants.hpp"
#include "file.hpp"
#include "property.hpp"
#include "account.hpp"

class Player
{
private:
    std::string username;
    std::string password;
    // int money = 20000; // currentBankBalance

    Account acc;

public:
    enum Status
    {
        ALIVE,
        IN_JAIL,
        DEAD
    };
    // Player(std::string s);
    Player(const std::string &name, const Account &a)
        : username{name}, acc{a}
    // initializer list
    {
        std::cout << "Constructor for player " << this->username << "\n";
    }
    ~Player()
    {
        std::cout << "Destructor for player " << this->username << "\n";
    }

    void passGo();
    void creditMoney(int money, Player &player);
    void debitMoney(int money, Player &player);
    void jailRescue();
    void rent();
    void buyProperty(Property &P);
    void buildHouse();
    int showBalance();

    // friend int credit(int money, Player &player);
};

// bank.money;
// parent - trasaction(credit, debit) , child - Operation(jail, rent, buy)
// player class <----friend----> operation class => retrive 2 things- username + bankbalance from Player
#endif