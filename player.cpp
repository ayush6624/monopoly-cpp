#include "player.h"

using namespace std;

void Player::creditMoney(int x, Player player)
{
    player.money += x;
}

void Player::debitMoney(int x, Player player)
{
    this->money += x;
    player.money -= x;
}

void Player::passGo()
{
    string promptName;
    cout << "Enter the name of player: ";
    cin >> promptName;
    if (promptName == p1.person)
    {

        p1.creditmoneY(100, bank);

        creditMoneyP1(passMoney);
        p1.remainingBalance();
        debitMoneyBank(passMoney);
        cout << "\nMoney With Bank is : " << bank.money;

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Pass go\t\t\t\t\t+" << passMoney << "\t\t\t\t\t\t-" << passMoney << endl;
        state.close();
        option();
    }
    else if (promptName == p2.person)
    {
        creditMoneyP2(passMoney);
        p2.remainingBalance();
        debitMoneyBank(passMoney);
        cout << "\nMoney With Bank is : " << bank.money;

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Pass go\t\t\t\t\t\t\t\t+" << passMoney << "\t\t\t-" << passMoney << endl;
        state.close();
        option();
    }
    else
    {
        cout << "\n=====Please enter a valid name.\n";
        passGo();
    }
}