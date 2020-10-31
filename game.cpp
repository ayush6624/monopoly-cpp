#include "game.hpp"
#include "constants.hpp"
using namespace std;
// int NUMBER_OF_PLAYERS = 6;
// vector<Player> players;

void makeObj()
{
    players.push_back(Player("Bank", (100000), (0)));
    for (int i = 1; i < 6; i++)
    {
        players.push_back(Player("Player #" + to_string(i), (10000), (0)));
    }
}

pair<Player *, int> getUserChoice()
{
    int id;
    cout << "Enter the Player ID: ";
    cin >> id;
    Player *tempPlayer = &players[id];
    return {tempPlayer, id};
}

void viewBalance()
{
    cout << "\t\tBank's Balance is " << players[0].showBalance() << "\n";
    for (int i = 1; i < constants::NUMBER_OF_PLAYERS; i++)
    {
        {
            cout << "\t\tBalance for " << players[i].username << " : " << players[i].showBalance() << "\n";
        }
    }
}

void option()
{
    makeObj();
    char mainChoice; //main menu choice
    while (1)
    {
        // system("clear");
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
        cout << "\n\n\tQ. Exit\n";                         //done
        cin >> mainChoice;
        if (mainChoice == 'q')
            return;

        // system("clear");
        switch (mainChoice)
        {
        case 'a':
        {
            auto temp = getUserChoice();
            temp.first->buyProperty();
            break;
        }

        case 'b':
            getUserChoice().first->passGo();
            break;

        case 'c':
            // getUserChoice<Portfolio>(true)->buildHouse();
            break;

        case 'd':
            getUserChoice().first->rent();

            break;
        case 'e':
            getUserChoice().first->jailRescue();
            break;

        case 'f':
            getUserChoice().first->mortgage();
            break;
        
        // case 'g':
        //     sellBankPlayer();
        //     break;
        case 'h':
            getUserChoice().first->loan();
            break;
        // case 'i':
        //     otherCrDr();
        //     break;
        case 'j':
            viewBalance();
            break;
        // case 'k':
        //     itemised();
        //     break;
        // case 'l':
        //     cout << "Exited";
        //     exit(0);
        //     break;
        default:
            cout << "sed life bro";
            option();
        }
    }
}