#include "property.hpp"
using namespace std;

Property P;

// Property::Property(){
//     smallProp = 0;
//     mediumProp = 0;
//     largeProp = 0;
//     noOfProperty = 0;
// }

void Property::setPropertyList(int n)
        {
        switch (n)
            {
                case 0:
                    smallProp++;
                    break;
                case 1:
                    mediumProp++;
                    break;
                case 2:
                    largeProp++;
                    break;

                default:
                    cout << "Enter valid size";
                    break;
             }
        }

void Property::getPropertyList(){
    cout<<"Total Properties are: "<<smallProp + mediumProp + largeProp<<endl<<endl;
}


