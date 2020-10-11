#include "file.hpp"
using namespace std;

File::File(string fileName)
{
    cout << "constructor\n";
    file.open(fileName);
}

File::~File()
{
    cout << "destructorr\n";
    file.close();
}
void File::read()
{
}

void File::write(string str)
{
    file.open(filenmae, ios::app);
    file << str << "\n";
}