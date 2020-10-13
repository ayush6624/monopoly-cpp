#include "player.hpp"
using namespace std;
Player bank("Bank");
// int STARTING_MONEY = 10000;
// int JAIL_MONEY = 100;
// int PASS_GO = 100;
// int NUMBER_OF_PLAYERS = 6;

Player::Player(string s){
    username = s;
}

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
    creditMoney(constants::PASS_GO, bank);
    // p.showBalance();
    cout << "\nMoney With Bank is : " << bank.money;
    ofstream state;
    state.open("log.txt", ios::app);
    state << "\nPass go\t\t\t\t\t+" << constants::PASS_GO << "\t\t\t\t\t\t-" << constants::PASS_GO << endl;
    state.close();
    // option();
}
void Player::jailRescue()
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

 void Player::rent()
{
        int rent = 300;
        // cout << "\n\nEnter the Rent of the Property:  " << endl;
        // cin >> debit;
        debitMoney(rent, bank);
        // p1.remainingBalance();
        creditMoney(rent, bank);
        // p2.remainingBalance();

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Rent \t\t\t\t\t-" << rent << "\t\t\t+" << rent << endl;
        state.close();
        // option();
    
    // else
    // {
    //     cout << "\n=====Please enter a valid name.\n";
    //     rent();
    // }
}

void Player::buildHouse()
{
        int pay = 500;
        debitMoney(pay, bank);
        // p1.remainingBalance();
        creditMoney(pay, bank);
        // p2.remainingBalance();
        cout << "\nMoney With Bank is : " << bank.money;
        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "House/Hotel\t\t\t\t-" << pay << "\t\t\t\t\t\t+" << pay << endl;
        state.close();
        // option();
    
    
    // else
    // {
    //     cout << "\n=====Please enter a valid name.\n";
    //     buildHouse();
    // }
}

void Player::viewBalance()
{
    cout << "\n\t====BALANCE WITH BANK: " << bank.money;
    cout << "\n\n\n\t====BALANCE WITH " << p1.person << " is: " << p1.money;
    cout << "\n\n\n\t====BALANCE WITH " << p2.person << " is: " << p2.money;
    // option();
}