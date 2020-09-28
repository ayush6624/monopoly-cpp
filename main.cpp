#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <fstream>
//monopoly application.

using namespace std;

//object declaration
char introPrompt;     // for intro signup/login
char newUsername[15]; //signup
char newPassword[15]; //signup
string inUsername;    //login
string inPassword;    //login
string promptName;

int newConf;
int propertyPrice;
int debit;
int credit;
int passMoney;
int jailMoney;
int loanMoneyP1;
int loanMoneyP2;

//functions declared
void option();
void intro();
void signup();
void login();
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
//functions described

void intro()
{
    //system("cls");
    cout << "\nWelcome to The Digital Game of Monopoly. \n";
    cout << "This is purely intended for digital payments for the game of Standard Monopoly with Rules specified \n";
    cout << "U need to signup for the 1st time to use this game.\n";
    cout << "\n\n      Press 1 for Login \n      Press 2 for Signup\n\n";
    cin >> introPrompt;

    switch (introPrompt)
    {
    case '1':
        cout << "OK please wait for a few seconds!!\n";
        //sleep(2000);

        login();
        break;

    case '2':
        signup();
        break;
    default:
        cout << "\nPlease enter a valid number. For security purposes the process will start again.\n";
        //sleep(2000);
        intro();
    }
    cout << "Login Procedure completed, Thank You\n";
}

void signup()
{
    cout << "\nENTER YOUR USERNAME: ";
    cin >> newUsername;
    cout << "\nYou entered the following Username: " << newUsername << endl;
    cout << "Press 1 to confirm or any other number to re-enter" << endl;
    cin >> newConf;
    if (newConf == 1)
    {

        cout << "Enter the password for this account\n";
        cin >> newPassword;

        ofstream signupFileU;
        signupFileU.open("loginU.dat", ios::binary | ios::ate | ios::app);
        signupFileU << newUsername << " " << newPassword << endl;
        signupFileU.close();

        //sleep(1000);
        cout << "You will be shortly redirected to the game \n";
    }
    else
    {
        cout << "PLEASE WAIT!!\n";
        //sleep(1000);
        //system("cls");
        signup();
    }
}

void login()
{

    cout << "Please enter your username:\n";
    cin >> inUsername;
    //sleep(1000);
    cout << "\nPlease enter your password:\n";
    cin >> inPassword;
    //sleep(1000);
    ifstream loginFileU;
    loginFileU.open("loginu.dat", ios::binary);
    size_t pos;
    string line;
    string credentials = inUsername + " " + inPassword;
    while (loginFileU.good())
    {
        getline(loginFileU, line);    // get line from file
        pos = line.find(credentials); // search
        if (pos != string::npos)      // string::npos is returned if string is not found
        {
            cout << "Found! \n";
            break;
            loginFileU.close();
        }

        else
        {
            cout << " =====Incorrect Credentials, Please try again...\n";
            //sleep(1000);
            //system("cls");
            cout << "\n\n =====Please re-enter your credentials=====\n\n";
            //sleep(700);
            main();
        }
    }
}

//CLASS DECLARED

class account
{
public:
    int money;
    string person;
    void getName();
    void declareAssets();
    void DebitsFromBank();
    void CreditsFromBank();
    void remainingBalance();
};

account p1;
account p2;
account bank;
//MAIN CODE STARTS HERE
int main()
{
    //login/sign-up Instance

    intro();
    //intro();
    //sleep(1500);

    cout << "\n\n\t\t\t /-/-/-/-/GAME LOADING, PLEASE WAIT!/-/-/-/-/\n\n";
    //sleep(2000);
    cout << "\t\t\t\t\t=======LOADING=======";
    //sleep(1000);
    //system("cls");

    int numberPlayers;

    cout << "Declare number of players and the name of players below\n";
    //sleep(500);
    cout << "Number of players: ";
    cin >> numberPlayers;
    cout << "\n         Name of Player 1: ";
    cin >> p1.person;
    cout << "\n\n         Name of Player 2: ";
    cin >> p2.person;
    cout << "Thank you, the name registered with the game are: " << p1.person << " and " << p2.person << endl;
    cout << "\n\n The game will begin in a few moments.....\n";
    //sleep(1000);

    bank.declareAssets();
    p1.declareAssets();
    p2.declareAssets();

    //sleep(1000);
    //system("cls");
    cout << "Please define Pass Go value: ";
    cin >> passMoney;
    cout << "\nPlease define Jail Rescue value: ";
    cin >> jailMoney;
    cout << "\nPlease bid on your own!";

    ofstream state;
    state.open("log.dat", ios::binary | ios::trunc);
    state << "Itemised Statements copyright software\n";
    state << "Type					Player1		Player2			Bank\n\n";
    state.close();
    //sleep(3000);
    option();

    return 0;
}

void option()
{

    char mainChoice; //main menu choice

    //system("cls");
    cout << "\n\tMAIN MENU";
    cout << "\n\n\tA. Buy Property/Utility";           //Log DONE
    cout << "\n\n\tB. Pass GO!";                       //LOG DONE
    cout << "\n\n\tC. Build a House/Hotel";            //log DONE
    cout << "\n\n\tD. Rent";                           //log DONE
    cout << "\n\n\tE. Jail Rescue";                    // log DONE
    cout << "\n\n\tF. Mortgage";                       //done
    cout << "\n\n\tG. Sell to Bank/Player";            //log done
    cout << "\n\n\tH. Loan";                           //log DONE
    cout << "\n\n\tI. Other Credits/Debits From Bank"; // no log DONE
    cout << "\n\n\tJ. View Balance";                   //DONE
    cout << "\n\n\tK. Itemised Statement";             //log done
    cout << "\n\n\tL. Exit\n";                         //done
    cin >> mainChoice;
    //sleep(400);
    //system("cls");
    switch (mainChoice)
    {
    case 'a':
        BuyProperty();

        break;

    case 'b':
        passGo();

        break;
    case 'c':
        buildHouse();

        break;
    case 'd':
        rent();

        break;
    case 'e':
        jailRescue();

        break;

    case 'f':
        mortgage();

        break;
    case 'g':
        sellBankPlayer();
        break;
    case 'h':
        loan();
        break;
    case 'i':
        otherCrDr();
        break;
    case 'j':
        viewBalance();
        break;
    case 'k':
        itemised();
        break;
    case 'l':
        //sleep(2000);
        cout << "Exited \n\t\tCredits- CodeNations";
        exit(0);
        break;
    default:
        cout << "no bro";
        //sleep(100);
        option();
    }
}

void account::declareAssets()
{

    cout << "Please define the initial amount to start with!!\nProcess will be looped for Bank, " << p1.person << " and " << p2.person << " in order.\n";
    cout << "Enter the Cash in hand: ";
    cin >> money;
    cout << endl;
}

void rent()
{
    cout << "Enter the name of player From Which Rent is to be collected: ";
    cin >> promptName;
    if (promptName == p1.person)
    {
        cout << "\n\nEnter the Rent of the Property:  " << endl;
        cin >> debit;
        debitMoneyP1(debit);
        p1.remainingBalance();
        creditMoneyP2(debit);
        p2.remainingBalance();
        //sleep(3000);

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Rent \t\t\t\t\t-" << debit << "\t\t\t+" << debit << endl;
        state.close();
        option();
    }
    else if (promptName == p2.person)
    {
        cout << "\n\nEnter the Rent of the Property:   ";
        cin >> debit;
        debitMoneyP2(debit);
        p2.remainingBalance();
        creditMoneyP1(debit);
        p1.remainingBalance();
        //sleep(3000);

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Rent \t\t\t\t\t+" << debit << "\t\t\t-" << debit << endl;
        state.close();
        option();
    }
    else
    {
        cout << "\n=====Please enter a valid name.\n";
        //sleep(1000);
        rent();
    }
}

void otherCrDr()
{

    cout << "Enter the Player name: ";
    cin >> promptName;

    if (promptName == p1.person)
    {
        cout << "1=====Credit from Bank======\n2=====Debit from Bank======\n\n";
        cin >> newConf;
        if (newConf == 1)
        {
            p1.CreditsFromBank();
        }
        else
        {
            p1.DebitsFromBank();
        }
    }
    else
    {
        if (newConf == 1)
        {
            p2.CreditsFromBank();
        }
        else
        {
            p2.DebitsFromBank();
        }
    }
    //sleep(1000);
    option();
}

void passGo()
{
    cout << "Enter the name of player: ";
    cin >> promptName;
    if (promptName == p1.person)
    {

        creditMoneyP1(passMoney);
        p1.remainingBalance();
        debitMoneyBank(passMoney);
        cout << "\nMoney With Bank is : " << bank.money;
        //sleep(2000);

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
        //sleep(2000);

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
        //sleep(2000);
        passGo();
    }
    //sleep(2000);
}

void buildHouse()
{
    cout << "Enter the name of player: ";
    cin >> promptName;
    if (promptName == p1.person)
    {
        cout << "\n\nEnter the price of the House/Hotel:  ";
        cin >> debit;
        debitMoneyP1(debit);
        p1.remainingBalance();
        creditMoneyBank(debit);
        cout << "\nMoney With Bank is : " << bank.money;
        //sleep(2500);

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "House/Hotel\t\t\t\t-" << debit << "\t\t\t\t\t\t+" << debit << endl;
        state.close();
        option();
    }
    else if (promptName == p2.person)
    {
        cout << "\n\nEnter the price of the House/Hotel:  ";
        cin >> debit;
        debitMoneyP2(debit);
        p2.remainingBalance();
        creditMoneyBank(debit);
        cout << "\nMoney With Bank is : " << bank.money;
        //sleep(2500);

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "House/Hotel\t\t\t\t\t\t\t-" << debit << "\t\t\t+" << debit << endl;
        state.close();
        option();
    }
    else
    {
        cout << "\n=====Please enter a valid name.\n";
        //sleep(2500);
        buildHouse();
    }
    //sleep(2000);
}

void jailRescue()
{
    cout << "Enter the name of player: ";
    cin >> promptName;
    if (promptName == p1.person)
    {
        cout << "\n\nYOU ARE FREE NOW!!! ";
        debitMoneyP1(jailMoney);
        p1.remainingBalance();
        creditMoneyBank(jailMoney);
        cout << "\nMoney With Bank is : " << bank.money;
        //sleep(2500);

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Jail Rescue\t\t\t\t-" << jailMoney << "\t\t\t\t\t\t+" << jailMoney << endl;
        state.close();
        option();
    }
    else if (promptName == p2.person)
    {
        cout << "\n\nYOU ARE FREE NOW!!! ";
        debitMoneyP2(jailMoney);
        p2.remainingBalance();
        creditMoneyBank(jailMoney);
        cout << "\nMoney With Bank is : " << bank.money;
        //sleep(2500);

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Jail Rescue\t\t\t\t\t\t\t-" << jailMoney << "\t\t\t+" << jailMoney << endl;
        state.close();
        option();
    }
    else
    {
        cout << "\n=====Please enter a valid name.\n";
        //sleep(2500);
        jailRescue();
    }
    //sleep(2000);
}

void mortgage()
{

    cout << "Enter the name of player: ";
    cin >> promptName;

    if (promptName == p1.person)
    {
        cout << "===1. Mortgage a property\n===2. Unmortgage a property\n";
        cin >> newConf;
        if (newConf == 1)
        {
            cout << "\n\nEnter the price of the property to be mortgaged: \n";
            int mort1P1, mort2P1;
            cin >> mort1P1;
            mort2P1 = mort1P1 / 2;
            creditMoneyP1(mort2P1);
            p1.remainingBalance();
            debitMoneyBank(mort2P1);
            cout << "\nMoney With Bank is : " << bank.money;

            //sleep(4000);

            ofstream state;
            state.open("log.dat", ios::binary | ios::app | ios::ate);
            state << endl
                  << "Mortgage\t\t\t\t+" << mort2P1 << "\t\t\t"
                  << "\t\t\t-" << mort2P1 << endl;
            state.close();
            option();
        }
        else
        {
            int inMortP1;
            cout << "Unmortgaging a property.\nEnter the cost of the property: \n";
            cin >> inMortP1;
            inMortP1 = inMortP1 * 0.1;
            cout << "Amount to be paid is: " << inMortP1;
            //sleep(1000);
            debitMoneyP1(inMortP1);
            p1.remainingBalance();
            creditMoneyBank(inMortP1);
            cout << "\nMoney With Bank is: " << bank.money;
            //sleep(4000);

            ofstream state;
            state.open("log.dat", ios::binary | ios::app | ios::ate);
            state << endl
                  << "Mortgage\t\t\t\t-" << inMortP1 << "\t\t\t"
                  << "\t\t\t+" << inMortP1 << endl;
            state.close();
            option();
        }
    }
    else if (promptName == p2.person)
    {

        cout << "===1. Mortgage a property\n===2. Unmortgage a property\n";
        cin >> newConf;
        if (newConf == 1)
        {
            cout << "\n\nEnter the price of the property to be mortgaged: \n";
            int mort1P2, mort2P2;
            cin >> mort1P2;
            mort2P2 = mort1P2 / 2;
            creditMoneyP2(mort2P2);
            p2.remainingBalance();
            debitMoneyBank(mort2P2);
            cout << "\nMoney With Bank is : " << bank.money;

            //sleep(4000);

            ofstream state;
            state.open("log.dat", ios::binary | ios::app | ios::ate);
            state << endl
                  << "Mortgage\t\t\t\t\t\t\t+" << mort2P2 << "\t\t\t-" << mort2P2 << endl;
            state.close();
            option();
        }
        else
        {
            int inMortP2;
            cout << "Unmortgaging a property.\nEnter the cost of the property: ";
            cin >> inMortP2;
            inMortP2 = inMortP2 * 0.1;
            cout << "\nAmount to be paid is: " << inMortP2 << endl;

            //sleep(1000);
            debitMoneyP2(inMortP2);
            p2.remainingBalance();
            creditMoneyBank(inMortP2);
            cout << "\nMoney With Bank is: " << bank.money;
            //sleep(4000);

            ofstream state;
            state.open("log.dat", ios::binary | ios::app | ios::ate);
            state << endl
                  << "Mortgage\t\t\t\t\t\t\t-" << inMortP2 << "\t\t\t+" << inMortP2 << endl;
            state.close();
            option();
        }
    }
    else
    {
        cout << "\n=====Please enter a valid name.\n";
        //sleep(1000);
        mortgage();
    }
    //sleep(1000);
    option();
}

void account::DebitsFromBank()
{
    cout << "Enter the money to Debit: ";
    cin >> debit;
    money = money - debit;
    cout << "Available Balance: " << money;
}

void account::CreditsFromBank()
{
    cout << "Enter the money to Credit: ";
    cin >> credit;
    money = money + credit;
    cout << "Available Balance: " << money;
}

void account::remainingBalance()
{
    cout << "Remaining balance for " << person << " is: " << money;
}

void BuyProperty()
{
    cout << "Enter the name of player: ";
    cin >> promptName;
    if (promptName == p1.person)
    {
        cout << "\n\nEnter the price of the property:  ";
        cin >> debit;
        debitMoneyP1(debit);
        p1.remainingBalance();
        creditMoneyBank(debit);
        cout << "\nMoney With Bank is : " << bank.money;
        //sleep(1000);

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Property Buy\t\t\t-" << debit << "\t\t\t"
              << "\t\t\t+" << debit << endl;
        state.close();
        option();
    }
    else if (promptName == p2.person)
    {
        cout << "\n\nEnter the price of the property:  ";
        cin >> debit;
        debitMoneyP2(debit);
        p2.remainingBalance();
        creditMoneyBank(debit);
        cout << "\nMoney With Bank is : " << bank.money;
        //sleep(1000);

        ofstream state;
        state.open("log.dat", ios::binary | ios::app | ios::ate);
        state << endl
              << "Property Buy\t\t\t\t\t\t-" << debit << "\t\t\t+" << debit << endl;
        state.close();
        option();
    }
    else
    {
        cout << "\n=====Please enter a valid name.\n";
        //sleep(1000);
        BuyProperty();
    }
    //sleep(1000);
    option();
}

void viewBalance()
{
    cout << "\n\t====BALANCE WITH BANK: " << bank.money;
    cout << "\n\n\n\t====BALANCE WITH " << p1.person << " is: " << p1.money;
    cout << "\n\n\n\t====BALANCE WITH " << p2.person << " is: " << p2.money;
    //sleep(3000);
    option();
}

void loan()
{
    cout << "\nThe rate of interest of loan is 5% per chance\n";
    cout << "Enter the name of player: ";
    cin >> promptName;

    if (promptName == p1.person)
    {
        cout << "\n===1. Get Loan\n===2. Return Loan\n";
        cin >> newConf;
        if (newConf == 1)
        {
            if (loanMoneyP1 == 0)
            {
                cout << "\n\nEnter the amount of loan needed:  ";
                cin >> loanMoneyP1;
                creditMoneyP1(loanMoneyP1);
                p1.remainingBalance();
                debitMoneyBank(loanMoneyP1);
                cout << "\nMoney With Bank is : " << bank.money;
                //sleep(4000);
                ofstream state;
                state.open("log.dat", ios::binary | ios::app | ios::ate);
                state << endl
                      << "Loan \t\t\t\t+" << loanMoneyP1 << "\t\t\t\t\t\t-" << loanMoneyP1 << endl;
                state.close();
                option();
            }

            else
            {
                cout << "You already have a loan!!!";
                //sleep(3000);
                option();
            }
        }

        else
        {

            cout << "Enter the number of rounds played: ";
            int roundP1;
            int fLoanP1;
            cin >> roundP1;
            fLoanP1 = 1.05 * loanMoneyP1 * roundP1;
            cout << "You have to give back " << fLoanP1;
            cout << "\nMoney will be deducted now.";
            debitMoneyP1(fLoanP1);
            creditMoneyBank(fLoanP1);
            p1.remainingBalance();
            cout << "\nRemaining money with bank: " << bank.money;
            //sleep(6000);

            ofstream state;
            state.open("log.dat", ios::binary | ios::app | ios::ate);
            state << endl
                  << "Loan \t\t\t\t-" << fLoanP1 << "\t\t\t\t\t\t+" << fLoanP1 << endl;
            state.close();
            option();
        }
    }
    else if (promptName == p2.person)
    {
        cout << "\n===1. Get Loan\n===2. Return Loan\n";
        cin >> newConf;
        if (newConf == 1)
        {
            if (loanMoneyP2 == 0)
            {
                cout << "\n\nEnter the amount of loan needed:  ";
                cin >> loanMoneyP2;
                creditMoneyP2(loanMoneyP2);
                p2.remainingBalance();
                debitMoneyBank(loanMoneyP2);
                cout << "\nMoney With Bank is : " << bank.money;
                //sleep(4000);
                ofstream state;
                state.open("log.dat", ios::binary | ios::app | ios::ate);
                state << endl
                      << "Loan \t\t\t\t\t\t\t+" << loanMoneyP2 << "\t\t\t-" << loanMoneyP2 << endl;
                state.close();
                option();
            }

            else
            {
                cout << "\nYou already have a loan!!!";
                //sleep(3000);
                option();
            }
        }
        else
        {

            cout << "Enter the number of rounds played: ";
            int roundP2;
            int fLoanP2;
            cin >> roundP2;
            fLoanP2 = 1.05 * loanMoneyP2 * roundP2;
            cout << "You have to give back " << fLoanP2;
            cout << "\nMoney will be deducted now.";
            debitMoneyP2(fLoanP2);
            creditMoneyBank(fLoanP2);
            p2.remainingBalance();
            cout << "\nRemaining money with bank: " << bank.money;
            //sleep(6000);

            ofstream state;
            state.open("log.dat", ios::binary | ios::app | ios::ate);
            state << endl
                  << "Rent \t\t\t\t\t\t\t-" << fLoanP2 << "\t\t\t+" << fLoanP2 << endl;
            state.close();
            option();
        }
    }
    else
    {
        cout << "\n=====Please enter a valid name.\n\n";
        //sleep(2500);
        loan();
    }
    //sleep(2000);
}

void sellBankPlayer()
{

    cout << "Enter the name of player whose property need to be sold: ";
    cin >> promptName;

    if (promptName == p1.person)
    {
        cout << "===1. Sell To Bank(at half the rate of property)\n===2. Sell to " << p2.person << endl;
        cin >> newConf;
        if (newConf == 1)
        {
            cout << "\n\nEnter the price of the property to be sold to bank: \n";
            int saleP1;
            cin >> saleP1;
            saleP1 = saleP1 / 2;
            creditMoneyP1(saleP1);
            p1.remainingBalance();
            debitMoneyBank(saleP1);
            cout << "\nMoney With Bank is : " << bank.money;

            //sleep(4000);

            ofstream state;
            state.open("log.dat", ios::binary | ios::app | ios::ate);
            state << endl
                  << "Sale    \t\t\t\t+" << saleP1 << "\t\t\t"
                  << "\t\t\t-" << saleP1 << endl;
            state.close();
            option();
        }
        else
        {
            int saleP1;
            cout << "Sell a property to " << p2.person << "\nEnter the amount by which u want to sell property: \n";
            cin >> saleP1;

            cout << "Amount to be paid is: " << saleP1 << endl;
            //sleep(1000);
            creditMoneyP1(saleP1);
            p1.remainingBalance();
            debitMoneyP2(saleP1);
            cout << "" << endl;
            p2.remainingBalance();
            //sleep(4000);

            ofstream state;
            state.open("log.dat", ios::binary | ios::app | ios::ate);
            state << endl
                  << "Sale \t\t\t\t\t-" << saleP1 << "\t\t\t+" << saleP1 << endl;
            state.close();
            option();
        }
    }
    else if (promptName == p2.person)
    {

        cout << "===1. Sell To Bank(at half the rate of property)\n===2. Sell to " << p1.person << endl;
        cin >> newConf;
        if (newConf == 1)
        {
            cout << "\n\nEnter the price of the property to be sold to bank: \n";
            int saleP2;
            cin >> saleP2;
            saleP2 = saleP2 / 2;
            creditMoneyP2(saleP2);
            p2.remainingBalance();
            debitMoneyBank(saleP2);
            cout << "\nMoney With Bank is : " << bank.money;

            //sleep(4000);

            ofstream state;
            state.open("log.dat", ios::binary | ios::app | ios::ate);
            state << endl
                  << "Sell   \t\t\t\t\t\t\t\t+" << saleP2 << "\t\t\t-" << saleP2 << endl;
            state.close();
            option();
        }
        else
        {
            int saleP2;
            cout << "Sell a property to " << p1.person << "\nEnter the amount by which u want to sell property: \n";
            cin >> saleP2;

            cout << "Amount to be paid is: " << saleP2 << endl;
            //sleep(1000);
            debitMoneyP1(saleP2);
            p1.remainingBalance();
            creditMoneyP2(saleP2);
            cout << "" << endl;
            p2.remainingBalance();
            //sleep(4000);

            ofstream state;
            state.open("log.dat", ios::binary | ios::app | ios::ate);
            state << endl
                  << "Sale   \t\t\t\t\t+" << saleP2 << "\t\t\t-" << saleP2 << endl;
            state.close();
            option();
        }
    }
    else
    {
        cout << "\n=====Please enter a valid name.\n";
        //sleep(1000);
        sellBankPlayer();
    }
    //sleep(1000);
    option();
}

void itemised()
{
    cout << "\t\t\t\t\tItemised Statement: \n\n";
    system("start notepad++ log.dat");
    //sleep(1000);
    option();
}

void creditMoneyP1(int x)
{
    p1.money = p1.money + x;
}

void creditMoneyP2(int x)
{
    p2.money = p2.money + x;
}

void creditMoneyBank(int x)
{
    bank.money = bank.money + x;
}

void debitMoneyP1(int x)
{
    p1.money = p1.money - x;
}

void debitMoneyP2(int x)
{
    p2.money = p2.money - x;
}
void debitMoneyBank(int x)
{
    bank.money = bank.money - x;
}