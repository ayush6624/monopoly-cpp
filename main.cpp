// FIX remove obsolete include statements
#include <unistd.h>
#include <bits/stdc++.h>
//monopoly application.

using namespace std;

// TODO Remove all global variables
//object declaration
char newUsername[15]; //signup
char newPassword[15]; //signup
string promptName;

int newConf;
int propertyPrice;
int debit;
int credit;
int passMoney;
int jailMoney;
int loanMoneyP1;
int loanMoneyP2;

// TODO Remove all global functions
//functions declared
// void option();
void intro();
void passGo();
void otherCrDr();
void BuyProperty();
void buildHouse();
void itemised();
void jailRescue();
void viewBalance();
void rent();
void sellBankPlayer();
void loan();
void mortgage();
int main();

void creditMoneyP1(int x);
void creditMoneyP2(int x);
void creditMoneyBank(int x);
void debitMoneyP1(int x);
void debitMoneyP2(int x);
void debitMoneyBank(int x);

//TODO Make a player class

#include "intro.hpp"
#include "user.hpp"
void intro()
{
    intro_f();
    char introPrompt;
    cin >> introPrompt;
    switch (introPrompt)
    {
    case '1':
        if (login())
        {
            system("clear");
            cout << "-----------Login Procedure completed, Thank You----------- \n";
            sleep(0.5);
        }
        else
        {
            system("clear");
            cout << "-----------Incorrect Credentials, Please try again-----------\n";
            sleep(2);
            main();
        }
        break;

    case '2':
        signup();
        break;
    default:
        // TODO : Make a common error function
        // clear the screen and show a warning page maybe?
        cout << "\nPlease enter a valid number. We'll start again!\n";
        sleep(2);
        intro();
    }
}

// TODO Make a function/class for file reading, writing, and validation

//TODO Refactor Account class

// FIX do not declare in global
// Account p1;
// Account p2;
// Account bank;
//MAIN CODE STARTS HERE

// TODO Remove all sleep statements
#include "game.hpp"

int main()
{
    //login/sign-up Instance
    intro();
    system("clear");
    cout << "-----------------LOADING-----------------\n";
    sleep(0.5);
    // system("clear");
    //  https://stackoverflow.com/questions/30821356/multiple-definition-first-defined-here-errors
    option();

    // int numberPlayers;

    // cout << "Declare number of players and the name of players below\n";
    // cout << "Number of players: ";
    // cin >> numberPlayers;
    // cout << "\n         Name of Player 1: ";
    // cin >> p1.person;
    // cout << "\n\n         Name of Player 2: ";
    // cin >> p2.person;
    // cout << "Thank you, the name registered with the game are: " << p1.person << " and " << p2.person << endl;
    // cout << "\n\n The game will begin in a few moments.....\n";

    // bank.declareAssets();
    // p1.declareAssets();
    // p2.declareAssets();

    // system("clear");
    // cout << "Please define Pass Go value: ";
    // cin >> passMoney;
    // cout << "\nPlease define Jail Rescue value: ";
    // cin >> jailMoney;
    // cout << "\nPlease bid on your own!";

    // ofstream state;
    // state.open("log.dat", ios::binary | ios::trunc);
    // state << "Itemised Statements copyright software\n";
    // state << "Type					Player1		Player2			Bank\n\n";
    // state.close();
    // option();
    // return 0;
}

// void otherCrDr()
// {

//     cout << "Enter the Player name: ";
//     cin >> promptName;

//     if (promptName == p1.person)
//     {
//         cout << "1=====Credit from Bank======\n2=====Debit from Bank======\n\n";
//         cin >> newConf;
//         if (newConf == 1)
//         {
//             p1.CreditsFromBank();
//         }
//         else
//         {
//             p1.DebitsFromBank();
//         }
//     }
//     else
//     {
//         if (newConf == 1)
//         {
//             p2.CreditsFromBank();
//         }
//         else
//         {
//             p2.DebitsFromBank();
//         }
//     }
//     option();
// }


// void sellBankPlayer()
// {

//     cout << "Enter the name of player whose property need to be sold: ";
//     cin >> promptName;

//     if (promptName == p1.person)
//     {
//         cout << "===1. Sell To Bank(at half the rate of property)\n===2. Sell to " << p2.person << endl;
//         cin >> newConf;
//         if (newConf == 1)
//         {
//             cout << "\n\nEnter the price of the property to be sold to bank: \n";
//             int saleP1;
//             cin >> saleP1;
//             saleP1 = saleP1 / 2;
//             creditMoneyP1(saleP1);
//             p1.remainingBalance();
//             debitMoneyBank(saleP1);
//             cout << "\nMoney With Bank is : " << bank.money;

//             ofstream state;
//             state.open("log.dat", ios::binary | ios::app | ios::ate);
//             state << endl
//                   << "Sale    \t\t\t\t+" << saleP1 << "\t\t\t"
//                   << "\t\t\t-" << saleP1 << endl;
//             state.close();
//             option();
//         }
//         else
//         {
//             int saleP1;
//             cout << "Sell a property to " << p2.person << "\nEnter the amount by which u want to sell property: \n";
//             cin >> saleP1;

//             cout << "Amount to be paid is: " << saleP1 << endl;
//             creditMoneyP1(saleP1);
//             p1.remainingBalance();
//             debitMoneyP2(saleP1);
//             cout << "" << endl;
//             p2.remainingBalance();

//             ofstream state;
//             state.open("log.dat", ios::binary | ios::app | ios::ate);
//             state << endl
//                   << "Sale \t\t\t\t\t-" << saleP1 << "\t\t\t+" << saleP1 << endl;
//             state.close();
//             option();
//         }
//     }
//     else if (promptName == p2.person)
//     {

//         cout << "===1. Sell To Bank(at half the rate of property)\n===2. Sell to " << p1.person << endl;
//         cin >> newConf;
//         if (newConf == 1)
//         {
//             cout << "\n\nEnter the price of the property to be sold to bank: \n";
//             int saleP2;
//             cin >> saleP2;
//             saleP2 = saleP2 / 2;
//             creditMoneyP2(saleP2);
//             p2.remainingBalance();
//             debitMoneyBank(saleP2);
//             cout << "\nMoney With Bank is : " << bank.money;

//             ofstream state;
//             state.open("log.dat", ios::binary | ios::app | ios::ate);
//             state << endl
//                   << "Sell   \t\t\t\t\t\t\t\t+" << saleP2 << "\t\t\t-" << saleP2 << endl;
//             state.close();
//             option();
//         }
//         else
//         {
//             int saleP2;
//             cout << "Sell a property to " << p1.person << "\nEnter the amount by which u want to sell property: \n";
//             cin >> saleP2;

//             cout << "Amount to be paid is: " << saleP2 << endl;
//             debitMoneyP1(saleP2);
//             p1.remainingBalance();
//             creditMoneyP2(saleP2);
//             cout << "" << endl;
//             p2.remainingBalance();

//             ofstream state;
//             state.open("log.dat", ios::binary | ios::app | ios::ate);
//             state << endl
//                   << "Sale   \t\t\t\t\t+" << saleP2 << "\t\t\t-" << saleP2 << endl;
//             state.close();
//             option();
//         }
//     }
//     else
//     {
//         cout << "\n=====Please enter a valid name.\n";
//         sellBankPlayer();
//     }
//     option();
// }

// void itemised()
// {
//     cout << "\t\t\t\t\tItemised Statement: \n\n";
//     system("start notepad++ log.dat");
//     option();
// }
