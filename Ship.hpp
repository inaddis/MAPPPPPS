#ifndef SHIP_HPP
#define SHIP_HPP

#include <vector>
#include <set>
#include <map>
#include <string>
#include "Cow.hpp"

class Cow;

class Ship {
private:
    std::string shipName;
    int numCows;
    Cow* cowInventory[100];

public:
    Ship(const std::string& shipName);
    ~Ship();

    void abductCow(Cow* cow);
    void dropOffCow();
    void dropOffCow(const std::string& cowID);
    void displayInventory() const;
};

#endif // SHIP_HPP
