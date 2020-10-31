#ifndef PROPERTY_H
#define PROPERTY_H
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include "constants.hpp"

class Property
{
private:
    std::vector<std::pair<int, int>> props;
    // double rentPercentage = 0.1;

public:
    Property();
    void setPropertyList(int n);
    void getPropertyList();
    int getPropPrice(const int &size);
    int getRentPrice(const int &size) { return constants::RENT_PERCENTAGE * getPropPrice(size); }
    // friend class Player;
};

#endif
