#include "property.hpp"
using namespace std;

// Property P;

// void Property::setPropertyList(int n)
//         {
//         switch (n)
//             {
//                 case 0:
//                     smallProp++;
//                     break;
//                 case 1:
//                     mediumProp++;
//                     break;
//                 case 2:
//                     largeProp++;
//                     break;

//                 default:
//                     cout << "Enter valid size";
//                     break;
//              }
//         }

// void Property::getPropertyList(){
//     cout<<"Total Properties are: "<<smallProp + mediumProp + largeProp<<endl<<endl;
// }
Property::Property()
{
    for (int i = 1; i <= 3; i++)
    {
        pair<int, int> temp = {i * 1000, i - 1}; // price, size
        props.push_back(temp);
    }
}
int Property::getPropPrice(const int &size)
{
    for (auto i : props)
        if (i.second == size)
            return i.first;
    return -1;
}