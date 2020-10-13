#include "user.hpp"

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
    string fi = File("loginU.txt").read();
    if (fi.find(credentials) != string::npos) return true;
    else return false;
}

void signup()
{
    cout << "\nEnter the username: ";
    string newUsername, newPassword;
    int newConf;
    cin >> newUsername;
    cout << "Enter the password for this Account\n";
    cin >> newPassword;
    File f("loginU.txt");
    f.write(newUsername + " " + newPassword);
}