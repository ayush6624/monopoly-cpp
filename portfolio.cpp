#include "portfolio.hpp"
using namespace std;

void Portfolio::addProperty(int size)
{
    // 0-small
    // 1-medium
    // 2-large

    switch (size)
    {
    case 0:
        smallProp++;
        noOfProperty++;
        break;
    case 1:
        mediumProp++;
        noOfProperty++;
        break;
    case 2:
        largeProp++;
        noOfProperty++;
        break;
    }
}

ostream &operator<<(ostream &out, const Portfolio &p)
{
    out << "Total Property\t " << p.noOfProperty;
    out << "Small Property:\t " << p.smallProp;
    out << "Medium Propery\t " << p.mediumProp;
    out << "Large Property:\t " << p.largeProp << "\n";
    return out;
}

// cout << Player.Properties[0]<<"\n";

void getProperty(const Portfolio &p)
{
    cout << p;
}
