#include "player.hpp"
using namespace std;

vector<Player> players;

int Player::showBalance()
{
    return this->acc.getBalanceMoney();
}

void Player::creditMoney(int x, Player &p)
{
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

void Player::buyProperty()
{
    int size;
    cout << "Enter Property size to buy: 0 -> small, 1 -> medium or 2 -> large\n";
    cin >> size;
    size = 0;
    int pay = portfolio.getPropPrice(size);
    debitMoney(pay, players[0]);
    cout << "\nMoney With bank is: " << players[0].acc.getBalanceMoney();
    ofstream state;
    state.open("log.dat", ios::binary | ios::app | ios::ate);
    state << endl
          << "Property Buy\t\t\t-" << pay << "\t\t\t"
          << "\t\t\t+" << pay << endl;
    state.close();
}

void Player::rent()
{
    int id;
    cout << "Enter player's ID who owns the property: ";
    cin >> id;
    int size;
    cout << "Enter Property size to rent: 0 -> small, 1 -> medium or 2 -> large\n";
    cin >> size;
    int rent = portfolio.getRentPrice(size);
    debitMoney(rent, players[id]);
    cout << "\nMoney With owner is: " << players[id].acc.getBalanceMoney();
    // cout << "\nMoney With player is: " << players[0].acc.getBalanceMoney();
    // File().log(constants::Status::RENT, "RENT", "\t\t\t\t\t+" + to_string(rent) + "\t\t\t\t\t\t" + to_string(rent) + "\n");
    ofstream state;
    state.open("log.dat", ios::binary | ios::app | ios::ate);
    state << endl
          << "Rent \t\t\t\t\t-" << rent << "\t\t\t+" << rent << endl;
    state.close();
}

void Player::mortgage()
{
    int newConf;
    cout << "===1. Mortgage a property\n===2. Unmortgage a property\n";
    cin >> newConf;
    int size;
    cout << "Enter Property size to rent: 0 -> small, 1 -> medium or 2 -> large\n";
    cin >> size;
    int propertyCost = portfolio.getPropPrice(size) / 2;
    if (newConf == 1)
    {

        creditMoney(propertyCost, players[0]);
        cout << "MORTGAGE SUCCESSFUL OF -> " << propertyCost << "\n";
    }
    else
    {
        debitMoney(constants::MORTGAGE_PERCENT * propertyCost, players[0]);
        cout << "UNMORTGAGE SUCCESSFUL OF -> " << constants::MORTGAGE_PERCENT * propertyCost << "\n";
    }
}

void Player::loan()
{

    int newConf, loanMoney;
    cout << "\nThe rate of interest of loan is 5% per chance\n";
    cout << "\n===1. Get a Loan\n===2. Return a Loan\n";
    cin >> newConf;
    if (newConf == 1)
    {

        cout << "\n\nEnter the amount of loan needed:  ";
        cin >> loanMoney;
        creditMoney(loanMoney, players[0]);
        this->loanValue = loanMoney;
        cout << "\nMoney With bank is: " << players[0].acc.getBalanceMoney();
        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Loan \t\t\t\t+" << loanMoney << "\t\t\t\t\t\t-" << loanMoney << endl;
        state.close();
    }

    else
    {
        cout << "Enter the number of rounds played: ";
        int roundP1;
        int fLoanP1;
        cin >> roundP1;
        fLoanP1 = (1 + (0.05 * roundP1)) * this->loanValue;
        cout << "You have to give back " << fLoanP1;
        cout << "\nMoney will be deducted now.";
        debitMoney(fLoanP1, players[0]);

        cout << "\nMoney With bank is: " << players[0].acc.getBalanceMoney();

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Loan \t\t\t\t-" << fLoanP1 << "\t\t\t\t\t\t+" << fLoanP1 << endl;
        state.close();
    }
}
