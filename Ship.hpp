#include <vector>
#include <set>

class Ship {
  private: 
    std::string shipName;
    std::vector<Cow*> cowInventory;
    int numCows;
    std::set<std::string> abductedCows;

  public: 
    Ship(const std::string& shipName) : shipName(shipName), numCows(0) {}

    ~Ship() {
      std::cout << shipName << " was destroyed..." << std::endl;
      for (Cow* cow : cowInventory) {
        delete cow;
      }
    }

    void abductCow(Cow* cow) {
      if (abductedCows.insert(cow->getName()).second) {
        cowInventory.push_back(cow);
        numCows++;
        std::cout << cow->getName() << " was abducted :O" << std::endl;
      }
      else {
        std::cout << "Error: There's already a cow with that name >:( abduction failed" << std::endl;
        delete cow;
      }
    }
};
