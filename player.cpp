#include "player.hpp"
using namespace std;

vector<Player> players;

int Player::showBalance()
{
    return this->acc.getBalanceMoney();
}

void Player::creditMoney(int x, Player &p)
{
    cout << "<-- this creditMoney is called test -->\n";
    this->acc.addMoney(x);
    p.acc.removeMoney(x);
}

void Player::debitMoney(int x, Player &p)
{
    this->acc.removeMoney(x);
    p.acc.addMoney(x);
}

void Player::passGo()
{
    cout << "--> " << this->acc.getBalanceMoney() << "\n";
    creditMoney(constants::PASS_GO, players[0]);
    cout << "\nMoney With bank is : " << players[0].acc.getBalanceMoney() << "\nMoney With " << this->username << " is : " << this->acc.getBalanceMoney() << "\n";
    // File().log(constants::status[0], "\t\t\t\t\t+" + to_string(constants::PASS_GO) + "\t\t\t\t\t\t" + to_string(constants::PASS_GO) + "\n");
}
void Player::jailRescue()
{
    cout << "\n\nYOU ARE FREE NOW!!!";
    debitMoney(constants::JAIL_MONEY, players[0]);
    cout << "\nMoney With bank is : " << players[0].acc.getBalanceMoney() << "\nMoney With  " << this->username << " is : " << this->acc.getBalanceMoney() << "\n";
    // File().log("JAIL", "\t\t\t\t\t+" + to_string(constants::JAIL_MONEY) + "\t\t\t\t\t\t" + to_string(constants::JAIL_MONEY) + "\n");
}

void Player::rent()
{
    int rent = 300;
    debitMoney(rent, players[0]);
    creditMoney(rent, players[0]);
    // File().log(constants::Status::RENT, "RENT", "\t\t\t\t\t+" + to_string(rent) + "\t\t\t\t\t\t" + to_string(rent) + "\n");
    ofstream state;
    state.open("log.dat", ios::binary | ios::app | ios::ate);
    state << endl
          << "Rent \t\t\t\t\t-" << rent << "\t\t\t+" << rent << endl;
    state.close();
}

void Player::buildHouse()
{
    int houseCost = 500;
    debitMoney(houseCost, players[0]);
    creditMoney(houseCost, players[0]);
    cout << "\nMoney With players[0] is : " << players[0].acc.getBalanceMoney();
    ofstream state;
    state.open("log.dat", ios::binary | ios::app | ios::ate);
    state << endl
          << "House/Hotel\t\t\t\t-" << houseCost << "\t\t\t\t\t\t+" << houseCost << endl;
    state.close();
    // option();

    // else
    // {
    //     cout << "\n=====Please enter a valid name.\n";
    //     buildHouse();
    // }
}

void Player::buyProperty(Portfolio &x)
{
    int pay;
    int size;
    cout << "Enter Property size to buy: 0 -> small, 1 -> medium or 2 -> large\n";
    cin >> size;

    x.addProperty(size);
    switch (size)
    {
    case 0:
        // pay = getPropPrice();

        break;
    case 1:
        pay = 200;
        break;
    case 2:
        pay = 300;
        break;

    default:
        cout << "Enter valid size";
        break;
    }

    debitMoney(pay, players[0]);
    creditMoney(pay, players[0]);
    cout << "\nMoney With bank is: " << players[0].acc.getBalanceMoney();
    ofstream state;
    state.open("log.dat", ios::binary | ios::app | ios::ate);
    state << endl
          << "Property Buy\t\t\t-" << pay << "\t\t\t"
          << "\t\t\t+" << pay << endl;
    state.close();
}
