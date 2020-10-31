#ifndef INDPROPERTY_H
#define INDPROPERTY_H
#include <iostream>
#include "property.hpp"

class Portfolio : public Property
{
private:
    int noOfProperty;
    int smallProp;
    int mediumProp;
    int largeProp;

public:
    Portfolio(int x)
    {
        this->noOfProperty = x;
        this->smallProp = x;
        this->mediumProp = x;
        this->largeProp = x;
    }
    void setPropertyList(int n);
    void addProperty(int size);
    void getProperty();
    friend std::ostream &operator<<(std::ostream &output, const Portfolio &p);
    // friend class Player;
};

#endif