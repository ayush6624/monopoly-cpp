#include "player.hpp"
using namespace std;
Player bank;
// int STARTING_MONEY = 10000;
// int JAIL_MONEY = 100;
// int PASS_GO = 100;
// int NUMBER_OF_PLAYERS = 6;

void Player::creditMoney(int x, Player &other)
{
    this->money += x;
    other.money -= x;
}

void Player::debitMoney(int x, Player &other)
{
    this->money -= x;
    other.money += x;
}

void Player::passGo()
{
    int PASS_GO = 100;
    creditMoney(100, bank);
    // p.showBalance();
    cout << "\nMoney With Bank is : " << bank.money;
    ofstream state;
    state.open("log.txt", ios::app);
    state << "\nPass go\t\t\t\t\t+" << PASS_GO << "\t\t\t\t\t\t-" << PASS_GO << endl;
    state.close();
    // option();
}
void Player::jailRescue(Player &p)
{
    int JAIL_MONEY = 100;
    cout << "\n\nYOU ARE FREE NOW!!!";
    debitMoney(JAIL_MONEY, bank);
    // p.showBalance();
    cout << "\nMoney With Bank is : " << bank.money;

    ofstream state;
    state.open("log.txt", ios::app);
    state << "\nJail Rescue\t\t\t\t-" << JAIL_MONEY << "\t\t\t\t\t\t+" << JAIL_MONEY << endl;
    state.close();
    // option();
}