#include <vector>
#include <set>
#include <map>

class Ship {
  private: 
    std::string shipName;
    std::map<std::string, Cow*> cowInventory;
    int numCows;
    std::set<std::string> abductedCows;

  public: 
    Ship(const std::string& shipName) : shipName(shipName), numCows(0) {}

    ~Ship() {
      std::cout << shipName << " was destroyed..." << std::endl;
      for (auto& pair : cowInventory) {
        delete pair.second;
      }
    }

    void abductCow(Cow* cow) {
      auto result = cowInventory.insert({ cow->getName(), cow });
      if (result.second) {
        numCows++;
        std::cout << cow->getName() << " was abducted :O" << std::endl;
      }
      else {
        std::cout << "Error: There's already a cow with that name >:( abduction failed" << std::endl;
        delete cow;
      }
    }

  void dropOffCow() {
    if (cowInventory.empty()) { 
      std::cout << "we don't have any cows :(" << std::endl;
      return;
    }

    auto it = std::next(cowInventory.begin(), cowInventory.size () / 2);
    delete it->second;
    cowInventory.erase(it);
    numCows--;
    
    std::cout << "we lost a cow :(" << std::endl;
};
