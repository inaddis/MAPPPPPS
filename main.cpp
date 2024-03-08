#include <iostream>
#include <vector>
#include "Cow.hpp"
#include "Ship.hpp"

void blowUpShip(Ship* ship);

int main() {
  std::vector<Ship*> ships;

  while (true) {
    std::cout << "Menu: " << std::endl;
    std::cout << "1. Create a ship\n2. Abduct a cow\n3. Self-Destruct (end program)\n4. Drop off a cow\n5. Display Inventory" << std::endl;
    std::cout << "Enter Choice: ";
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
        }
        else {
          std::cout << "Error: Invalid ship index." << std::endl;
          delete newCow;
        }
        break;
      }
      case 3: {
        if (!ships.empty()) {
          int shipIndexx;
          std::cout << "Choose a ship to blow up (1-" << ships.size() << "): ";
          std::cin >> shipIndexx;

          if (shipIndexx > 0 && shipIndexx <= ships.size()) {
            blowUpShip(ships[shipIndexx - 1]);
            ships.erase(ships.begin() + shipIndexx - 1);
          }
          else {
            std::cout << "Error Invalid ship index." << std::endl;
          }
        }

        if (ships.empty()) {
          std::cout << "Quitting program..." << std::endl;
          return 0;
        }
        break;
      }
      case 4: {
        std::cout << "1. Drop off random cow\n2. Drop off specific cow" << std::endl;
        std::cout << "Enter choice: ";
        int choicee;
        std::cin >> choicee;

        if (choicee == 1) {
          dropOffCow();
        }
        else {
          //drop off cow id
        }
        break;
      }
      case 5: {
        if (!ships.empty()) {
          int shipInddex;
          std::cout << "Choose a ship to display inventory (1-" << ships.size() << "): ";
          std::cin >> shipInddex;

          if (shipInddex > 0 && shipInddex <= ships.size()) {
            for (const auto& pair : ships[shipInddex -1]->getCowInventory()) {
              std::cout << pair.second << std::endl;
            }
          }
          else {
            std::cout << "Error: that ship doesn't exist." << std::endl;
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
