#include "file.hpp"
using namespace std;

File::File(string fileName)
{
    fileRead.open(fileName);
    fileWrite.open(fileName, ios::app);
    fileLog.open("log.txt", ios::app);
}
// TODO log after players login and logout
File::~File()
{
    fileWrite.close();
    fileRead.close();
    fileLog.close();
}

string File::read()
{
    string ans = "", line;
    while (getline(fileRead, line))
        ans += line + "\n";
    return ans;
}

void File::write(string str)
{
    fileWrite << str << "\n";
}

void File::log(string eventType, string str)
{
    fileLog << eventType << "\t\t\t\t" << str << "\n";
    
}