#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include "Cow.hpp"
#include "ship.hpp"

void blowUpShip(Ship* ship);

int main() {
    std::vector<Ship*> ships;

    while (true) {
        std::cout << "Menu:\n"
                  << "1. Create a ship\n"
                  << "2. Abduct a cow\n"
                  << "3. Self-Destruct (end program)\n"
                  << "4. Drop off a cow\n"
                  << "5. Display Inventory\n"
                  << "Enter Choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string shipName;
                std::cout << "Enter ship name: ";
                std::cin >> shipName;
                Ship* newShip = new Ship(shipName);
                ships.push_back(newShip);
                break;
            }
            case 2: {
                if (ships.empty()) {
                    std::cout << "Error: No ships available. Create a ship first." << std::endl;
                    break;
                }

                std::string cowName;
                std::cout << "Enter cow name: ";
                std::cin >> cowName;

                Cow* newCow = new Cow(cowName);

                int shipIndex;
                std::cout << "Choose a ship to abduct the cow (1-" << ships.size() << "): ";
                std::cin >> shipIndex;

                if (shipIndex > 0 && shipIndex <= ships.size()) {
                    ships[shipIndex - 1]->abductCow(newCow);
                } else {
                    std::cout << "Error: Invalid ship index." << std::endl;
                    delete newCow;
                }
                break;
            }
            case 3: {
                if (!ships.empty()) {
                    int shipIndex;
                    std::cout << "Choose a ship to blow up (1-" << ships.size() << "): ";
                    std::cin >> shipIndex;

                    if (shipIndex > 0 && shipIndex <= ships.size()) {
                        blowUpShip(ships[shipIndex - 1]);
                        ships.erase(ships.begin() + shipIndex - 1);
                    } else {
                        std::cout << "Error: Invalid ship index." << std::endl;
                    }
                }

                if (ships.empty()) {
                    std::cout << "Quitting program..." << std::endl;
                    return 0;
                }
                break;
            }
            case 4: {
                if (ships.empty()) {
                    std::cout << "Error: No ships available. Create a ship first." << std::endl;
                    break;
                }

                std::cout << "1. Drop off random cow\n2. Drop off specific cow\nEnter choice: ";
                int subChoice;
                std::cin >> subChoice;

                if (subChoice == 1) {
                    int shipIndex;
                    std::cout << "Choose a ship to drop off a cow (1-" << ships.size() << "): ";
                    std::cin >> shipIndex;

                    if (shipIndex > 0 && shipIndex <= ships.size()) {
                        ships[shipIndex - 1]->dropOffCow();
                    } else {
                        std::cout << "Error: Invalid ship index." << std::endl;
                    }
                } else if (subChoice == 2) {
                    int shipIndex;
                    std::cout << "Choose a ship to drop off a cow (1-" << ships.size() << "): ";
                    std::cin >> shipIndex;

                    if (shipIndex > 0 && shipIndex <= ships.size()) {
                        std::string cowID;
                        std::cout << "Enter the Cow ID to drop off: ";
                        std::cin >> cowID;
                        ships[shipIndex - 1]->dropOffCow(cowID);
                    } else {
                        std::cout << "Error: Invalid ship index." << std::endl;
                    }
                }
                break;
            }
            case 5: {
                if (!ships.empty()) {
                    int shipIndex;
                    std::cout << "Choose a ship to display inventory (1-" << ships.size() << "): ";
                    std::cin >> shipIndex;

                    if (shipIndex > 0 && shipIndex <= ships.size()) {
                        ships[shipIndex - 1]->displayInventory();
                    } else {
                        std::cout << "Error: Invalid ship index." << std::endl;
                    }
                }
                break;
            }
            default: 
                std::cout << "Error: Invalid choice. Please try again." << std::endl;
        }
    }
}

void blowUpShip(Ship* ship) {
    delete ship;
}
