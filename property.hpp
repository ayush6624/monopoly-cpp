#ifndef PROPERTY_H
#define PROPERTY_H
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

class Property
{
private:
    Property();
    std::pair<int, int> smallProp = {1000, 0}; // price, size
    std::pair<int, int> mediumProp = {2000, 1};
    std::pair<int, int> largeProp = {3000, 2};
    double rentPercentage = 0.1;

public:
    // Property();
    // void setPropertyList(int n);
    // void getPropertyList();
    int getRentPrice(const std::pair<int, int> &prop) { return (int)rentPercentage * prop.first; }
    int getPropPrice(const std::pair<int, int> &prop) { return prop.first; }

    // friend class Player;
};

#endif
