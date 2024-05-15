#include "Ship.hpp"
#include "Cow.hpp"
#include <iostream>

Ship::Ship(const std::string& shipName) : shipName(shipName), numCows(0) {
    for (int i = 0; i < 100; i++) {
        cowInventory[i] = nullptr;
    }
}

    Ship::~Ship() {
    std::cout << shipName << " was destroyed..." << std::endl;
    for (int i = 0; i < 100; ++i) {
        if (cowInventory[i] != nullptr) {
            delete cowInventory[i];
        }
    }
}

   void Ship::abductCow(Cow* cow) {
    size_t index = cow->getHash();
    if (cowInventory[index] == nullptr) {
        cowInventory[index] = cow;
        ++numCows;
        std::cout << cow->getName() << " was abducted :O" << std::endl;
    } else {
        std::cout << "Error: There's already a cow with that name >:( abduction failed" << std::endl;
        delete cow;
    }
}

  void Ship::dropOffCow() {
    if (numCows == 0) {
        std::cout << "We don't have any cows :(" << std::endl;
        return;
    }

    for (int i = 0; i < 100; ++i) {
        if (cowInventory[i] != nullptr) {
            delete cowInventory[i];
            cowInventory[i] = nullptr;
            --numCows;
            std::cout << "We lost a cow :(" << std::endl;
            return;
        }
    }
}

void Ship::dropOffCow(const std::string& cowID) {
    Cow tempCow(cowID);
    size_t index = tempCow.getHash();
    if (cowInventory[index] != nullptr && cowInventory[index]->getName() == cowID) {
        delete cowInventory[index];
        cowInventory[index] = nullptr;
        --numCows;
        std::cout << cowID << " was dropped off." << std::endl;
    } else {
        std::cout << "Error: " << cowID << " doesn't exist :|" << std::endl;
    }
}

void Ship::displayInventory() const {
    for (int i = 0; i < 100; ++i) {
        if (cowInventory[i] != nullptr) {
            std::cout << *cowInventory[i] << std::endl;
        }
    }
}
