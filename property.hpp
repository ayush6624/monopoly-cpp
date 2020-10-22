#ifndef PROPERTY_H
#define PROPERTY_H
#include <iostream>
#include<vector>
#include <fstream>

class Property
{
private:
    Property ();
    // vector<int> price = {100,200,300};
    int price = 100;
    int propertySize=0;
    int noOfProperty=0;
    int smallProp=0;
    int mediumProp=0;
    int largeProp=0;
public:
        // Property();
        void setPropertyList(int n);
        void getPropertyList();


    friend class Player;
};

#endif