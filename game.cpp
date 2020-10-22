#include "game.hpp"
#include "constants.hpp"
using namespace std;
// int NUMBER_OF_PLAYERS = 6;
vector<Player> players;
Player getUserChoice()
{
    int id;
    cout << "Enter the Player ID: ";
    cin >> id;
    return players[id];
}

void option()
{
    for (int i = 0; i < constants::NUMBER_OF_PLAYERS; i++)
    {
        players.push_back(Player("Player #" + to_string(i)));
    }
    char mainChoice; //main menu choice
    while (1)
    {
        system("clear");
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

        system("clear");
        switch (mainChoice)
        {
        case 'a':
            // getUserChoice().buyProperty();
            break; 

        case 'b':
            getUserChoice().passGo();
            break;
        case 'c':
            getUserChoice().buildHouse();

            break;
        case 'd':
            getUserChoice().rent();

            break;
        case 'e':
            getUserChoice().jailRescue();
            break;

        // case 'f':
        //     mortgage();

        //     break;
        // case 'g':
        //     sellBankPlayer();
        //     break;
        // case 'h':
        //     loan();
        //     break;
        // case 'i':
        //     otherCrDr();
        //     break;
        // case 'j':
        //     viewBalance();
        //     break;
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