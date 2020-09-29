#include "account.h"

using namespace std;

void Account::declareAssets()
{
    // cout << "Please define the initial amount to start with!!\nProcess will be looped for Bank, " << p1.person << " and " << p2.person << " in order.\n";
    cout << "Enter the Cash in hand: ";
    cin >> money;
    cout << "\n";
}

void Account::DebitsFromBank()
{
    int debit;
    cout << "Enter the money to Debit: ";
    cin >> debit;
    money = money - debit;
    cout << "Available Balance: " << money;
}

void Account::CreditsFromBank()
{
    int credit;
    cout << "Enter the money to Credit: ";
    cin >> credit;
    money = money + credit;
    cout << "Available Balance: " << money;
}

void Account::remainingBalance()
{
    cout << "Remaining balance for " << person << " is: " << money;
}
