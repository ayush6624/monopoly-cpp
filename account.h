#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

class Account
{
public:
    int money;
    std::string person; // FIX Remove
    void getName();     // FIX Remove
    void declareAssets();
    void DebitsFromBank();
    void CreditsFromBank();
    void remainingBalance();
    Account()
    {
        std::cout << "called"
                  << "-----------------------------------------\n";
    }
};

#endif