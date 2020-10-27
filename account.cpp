#include "account.hpp"
using namespace std;

// int credit(int balanceMoney, Account &account)
// {
//     cout<<"hi";
// }

int Account::getBalanceMoney()
{
    return balanceMoney;
}

void Account::addMoney(int x)
{
    cout << "<-- this addMoney is called again test -->\n";
    // TODO add bankruptcy checks later
    int res = this->balanceMoney + x;
    this->balanceMoney = res;
    // this->balanceMoney += x;
    cout << "==== ADD DEBUG " << this->balanceMoney << "\n";
}

void Account::removeMoney(int x)
{
    this->balanceMoney -= x;
    cout << "==== REMOVE DEBUG " << this->balanceMoney << "\n";
}