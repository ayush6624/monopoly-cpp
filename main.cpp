// FIX remove obsolete include statements
#include <unistd.h>
#include <bits/stdc++.h>
#include "account.hpp"
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
void option();
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
            cout << "----------- Login Procedure completed, Thank You ----------- \n";
            sleep(2);
        }
        else
        {
            system("clear");
            cout << " =====Incorrect Credentials, Please try again...\n";
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
    sleep(2);
    system("clear");
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
    return 0;
}

// void rent()
// {
//     cout << "Enter the name of player From Which Rent is to be collected: ";
//     cin >> promptName;
//     if (promptName == p1.person)
//     {
//         cout << "\n\nEnter the Rent of the Property:  " << endl;
//         cin >> debit;
//         debitMoneyP1(debit);
//         p1.remainingBalance();
//         creditMoneyP2(debit);
//         p2.remainingBalance();

//         ofstream state;
//         state.open("log.dat", ios::binary | ios::app | ios::ate);
//         state << endl
//               << "Rent \t\t\t\t\t-" << debit << "\t\t\t+" << debit << endl;
//         state.close();
//         option();
//     }
//     else if (promptName == p2.person)
//     {
//         cout << "\n\nEnter the Rent of the Property:   ";
//         cin >> debit;
//         debitMoneyP2(debit);
//         p2.remainingBalance();
//         creditMoneyP1(debit);
//         p1.remainingBalance();

//         ofstream state;
//         state.open("log.dat", ios::binary | ios::app | ios::ate);
//         state << endl
//               << "Rent \t\t\t\t\t+" << debit << "\t\t\t-" << debit << endl;
//         state.close();
//         option();
//     }
//     else
//     {
//         cout << "\n=====Please enter a valid name.\n";
//         rent();
//     }
// }

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

// #include "game.h"
// void buildHouse()
// {
//     cout << "Enter the name of player: ";
//     cin >> promptName;
//     if (promptName == p1.person)
//     {
//         cout << "\n\nEnter the price of the House/Hotel:  ";
//         cin >> debit;
//         debitMoneyP1(debit);
//         p1.remainingBalance();
//         creditMoneyBank(debit);
//         cout << "\nMoney With Bank is : " << bank.money;

//         ofstream state;
//         state.open("log.dat", ios::binary | ios::app | ios::ate);
//         state << endl
//               << "House/Hotel\t\t\t\t-" << debit << "\t\t\t\t\t\t+" << debit << endl;
//         state.close();
//         option();
//     }
//     else if (promptName == p2.person)
//     {
//         cout << "\n\nEnter the price of the House/Hotel:  ";
//         cin >> debit;
//         debitMoneyP2(debit);
//         p2.remainingBalance();
//         creditMoneyBank(debit);
//         cout << "\nMoney With Bank is : " << bank.money;

//         ofstream state;
//         state.open("log.dat", ios::binary | ios::app | ios::ate);
//         state << endl
//               << "House/Hotel\t\t\t\t\t\t\t-" << debit << "\t\t\t+" << debit << endl;
//         state.close();
//         option();
//     }
//     else
//     {
//         cout << "\n=====Please enter a valid name.\n";
//         buildHouse();
//     }
// }

// void mortgage()
// {

//     cout << "Enter the name of player: ";
//     cin >> promptName;

//     if (promptName == p1.person)
//     {
//         cout << "===1. Mortgage a property\n===2. Unmortgage a property\n";
//         cin >> newConf;
//         if (newConf == 1)
//         {
//             cout << "\n\nEnter the price of the property to be mortgaged: \n";
//             int mort1P1, mort2P1;
//             cin >> mort1P1;
//             mort2P1 = mort1P1 / 2;
//             creditMoneyP1(mort2P1);
//             p1.remainingBalance();
//             debitMoneyBank(mort2P1);
//             cout << "\nMoney With Bank is : " << bank.money;

//             ofstream state;
//             state.open("log.dat", ios::binary | ios::app | ios::ate);
//             state << endl
//                   << "Mortgage\t\t\t\t+" << mort2P1 << "\t\t\t"
//                   << "\t\t\t-" << mort2P1 << endl;
//             state.close();
//             option();
//         }
//         else
//         {
//             int inMortP1;
//             cout << "Unmortgaging a property.\nEnter the cost of the property: \n";
//             cin >> inMortP1;
//             inMortP1 = inMortP1 * 0.1;
//             cout << "Amount to be paid is: " << inMortP1;
//             debitMoneyP1(inMortP1);
//             p1.remainingBalance();
//             creditMoneyBank(inMortP1);
//             cout << "\nMoney With Bank is: " << bank.money;

//             ofstream state;
//             state.open("log.dat", ios::binary | ios::app | ios::ate);
//             state << endl
//                   << "Mortgage\t\t\t\t-" << inMortP1 << "\t\t\t"
//                   << "\t\t\t+" << inMortP1 << endl;
//             state.close();
//             option();
//         }
//     }
//     else if (promptName == p2.person)
//     {

//         cout << "===1. Mortgage a property\n===2. Unmortgage a property\n";
//         cin >> newConf;
//         if (newConf == 1)
//         {
//             cout << "\n\nEnter the price of the property to be mortgaged: \n";
//             int mort1P2, mort2P2;
//             cin >> mort1P2;
//             mort2P2 = mort1P2 / 2;
//             creditMoneyP2(mort2P2);
//             p2.remainingBalance();
//             debitMoneyBank(mort2P2);
//             cout << "\nMoney With Bank is : " << bank.money;

//             ofstream state;
//             state.open("log.dat", ios::binary | ios::app | ios::ate);
//             state << endl
//                   << "Mortgage\t\t\t\t\t\t\t+" << mort2P2 << "\t\t\t-" << mort2P2 << endl;
//             state.close();
//             option();
//         }
//         else
//         {
//             int inMortP2;
//             cout << "Unmortgaging a property.\nEnter the cost of the property: ";
//             cin >> inMortP2;
//             inMortP2 = inMortP2 * 0.1;
//             cout << "\nAmount to be paid is: " << inMortP2 << endl;

//             debitMoneyP2(inMortP2);
//             p2.remainingBalance();
//             creditMoneyBank(inMortP2);
//             cout << "\nMoney With Bank is: " << bank.money;

//             ofstream state;
//             state.open("log.dat", ios::binary | ios::app | ios::ate);
//             state << endl
//                   << "Mortgage\t\t\t\t\t\t\t-" << inMortP2 << "\t\t\t+" << inMortP2 << endl;
//             state.close();
//             option();
//         }
//     }
//     else
//     {
//         cout << "\n=====Please enter a valid name.\n";
//         mortgage();
//     }
//     option();
// }

// void BuyProperty()
// {
//     cout << "Enter the name of player: ";
//     cin >> promptName;
//     if (promptName == p1.person)
//     {
//         cout << "\n\nEnter the price of the property:  ";
//         cin >> debit;
//         debitMoneyP1(debit);
//         p1.remainingBalance();
//         creditMoneyBank(debit);
//         cout << "\nMoney With Bank is : " << bank.money;

//         ofstream state;
//         state.open("log.dat", ios::binary | ios::app | ios::ate);
//         state << endl
//               << "Property Buy\t\t\t-" << debit << "\t\t\t"
//               << "\t\t\t+" << debit << endl;
//         state.close();
//         option();
//     }
//     else if (promptName == p2.person)
//     {
//         cout << "\n\nEnter the price of the property:  ";
//         cin >> debit;
//         debitMoneyP2(debit);
//         p2.remainingBalance();
//         creditMoneyBank(debit);
//         cout << "\nMoney With Bank is : " << bank.money;

//         ofstream state;
//         state.open("log.dat", ios::binary | ios::app | ios::ate);
//         state << endl
//               << "Property Buy\t\t\t\t\t\t-" << debit << "\t\t\t+" << debit << endl;
//         state.close();
//         option();
//     }
//     else
//     {
//         cout << "\n=====Please enter a valid name.\n";
//         BuyProperty();
//     }
//     option();
// }

// void viewBalance()
// {
//     cout << "\n\t====BALANCE WITH BANK: " << bank.money;
//     cout << "\n\n\n\t====BALANCE WITH " << p1.person << " is: " << p1.money;
//     cout << "\n\n\n\t====BALANCE WITH " << p2.person << " is: " << p2.money;
//     option();
// }

// void loan()
// {
//     cout << "\nThe rate of interest of loan is 5% per chance\n";
//     cout << "Enter the name of player: ";
//     cin >> promptName;

//     if (promptName == p1.person)
//     {
//         cout << "\n===1. Get Loan\n===2. Return Loan\n";
//         cin >> newConf;
//         if (newConf == 1)
//         {
//             if (loanMoneyP1 == 0)
//             {
//                 cout << "\n\nEnter the amount of loan needed:  ";
//                 cin >> loanMoneyP1;
//                 creditMoneyP1(loanMoneyP1);
//                 p1.remainingBalance();
//                 debitMoneyBank(loanMoneyP1);
//                 cout << "\nMoney With Bank is : " << bank.money;
//                 ofstream state;
//                 state.open("log.dat", ios::binary | ios::app | ios::ate);
//                 state << endl
//                       << "Loan \t\t\t\t+" << loanMoneyP1 << "\t\t\t\t\t\t-" << loanMoneyP1 << endl;
//                 state.close();
//                 option();
//             }

//             else
//             {
//                 cout << "You already have a loan!!!";
//                 option();
//             }
//         }

//         else
//         {

//             cout << "Enter the number of rounds played: ";
//             int roundP1;
//             int fLoanP1;
//             cin >> roundP1;
//             fLoanP1 = 1.05 * loanMoneyP1 * roundP1;
//             cout << "You have to give back " << fLoanP1;
//             cout << "\nMoney will be deducted now.";
//             debitMoneyP1(fLoanP1);
//             creditMoneyBank(fLoanP1);
//             p1.remainingBalance();
//             cout << "\nRemaining money with bank: " << bank.money;

//             ofstream state;
//             state.open("log.dat", ios::binary | ios::app | ios::ate);
//             state << endl
//                   << "Loan \t\t\t\t-" << fLoanP1 << "\t\t\t\t\t\t+" << fLoanP1 << endl;
//             state.close();
//             option();
//         }
//     }
//     else if (promptName == p2.person)
//     {
//         cout << "\n===1. Get Loan\n===2. Return Loan\n";
//         cin >> newConf;
//         if (newConf == 1)
//         {
//             if (loanMoneyP2 == 0)
//             {
//                 cout << "\n\nEnter the amount of loan needed:  ";
//                 cin >> loanMoneyP2;
//                 creditMoneyP2(loanMoneyP2);
//                 p2.remainingBalance();
//                 debitMoneyBank(loanMoneyP2);
//                 cout << "\nMoney With Bank is : " << bank.money;
//                 ofstream state;
//                 state.open("log.dat", ios::binary | ios::app | ios::ate);
//                 state << endl
//                       << "Loan \t\t\t\t\t\t\t+" << loanMoneyP2 << "\t\t\t-" << loanMoneyP2 << endl;
//                 state.close();
//                 option();
//             }

//             else
//             {
//                 cout << "\nYou already have a loan!!!";
//                 option();
//             }
//         }
//         else
//         {

//             cout << "Enter the number of rounds played: ";
//             int roundP2;
//             int fLoanP2;
//             cin >> roundP2;
//             fLoanP2 = 1.05 * loanMoneyP2 * roundP2;
//             cout << "You have to give back " << fLoanP2;
//             cout << "\nMoney will be deducted now.";
//             debitMoneyP2(fLoanP2);
//             creditMoneyBank(fLoanP2);
//             p2.remainingBalance();
//             cout << "\nRemaining money with bank: " << bank.money;

//             ofstream state;
//             state.open("log.dat", ios::binary | ios::app | ios::ate);
//             state << endl
//                   << "Rent \t\t\t\t\t\t\t-" << fLoanP2 << "\t\t\t+" << fLoanP2 << endl;
//             state.close();
//             option();
//         }
//     }
//     else
//     {
//         cout << "\n=====Please enter a valid name.\n\n";
//         loan();
//     }
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

// //TODO Comment out

// void creditMoneyP1(int x)
// {
//     p1.money = p1.money + x;
// }

// void creditMoneyP2(int x)
// {
//     p2.money = p2.money + x;
// }

// void creditMoneyBank(int x)
// {
//     bank.money = bank.money + x;
// }

// void debitMoneyP1(int x)
// {
//     p1.money = p1.money - x;
// }

// void debitMoneyP2(int x)
// {
//     p2.money = p2.money - x;
// }
// void debitMoneyBank(int x)
// {
//     bank.money = bank.money - x;
// }
