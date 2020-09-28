#include "user.h"

using namespace std;

bool login()
{
    string inUsername;
    string inPassword;
    system("clear");
    cout << "Username :\n";
    cin >> inUsername;
    cout << "\nPassword :\n";
    cin >> inPassword;
    string credentials = inUsername + " " + inPassword;
    fstream file("loginU.txt");
    unordered_set<string> res;
    string user, password;
    while (file >> user >> password)
    {
        cout << user << password << "->\n";
        res.insert(user + " " + password);
    }
    if (res.find(credentials) != res.end())
        return true;
    else
        return false;
}

void signup()
{
    cout << "\nENTER YOUR USERNAME: ";
    string newUsername, newPassword;
    int newConf;
    cin >> newUsername;
    cout << "\nYou entered the following Username: " << newUsername << endl;
    cout << "Enter the password for this Account\n";
    cin >> newPassword;
    ofstream signupFileU;
    signupFileU.open("loginU.txt", ios::app);
    signupFileU
        << newUsername << " " << newPassword << endl;
    signupFileU.close();
}