#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

class Account
{
private:
    int balanceMoney;

public:
    Account(int x)
        : balanceMoney{x} { std::cout << "ACCOUNT CONSTRUCTOR\n"; }
    ~Account() { std::cout << "ACCOUNT DESTRUCTOR\n"; }
    int getBalanceMoney();
    void addMoney(int x);
    void removeMoney(int x);
    // friend int credit(int balanceMoney, Account &account);
};

#endif
