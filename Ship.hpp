#include <vector>
#include <set>
#include <map>
#include <string>

class Ship {
  private: 
    std::string shipName;
    std::map<std::string, Cow*> cowInventory;
    int numCows;
    std::set<std::string> abductedCows;

  public: 
    Ship(const std::string& shipName);

    ~Ship();

    void abductCow(Cow* cow);

  const std::map<std::string, Cow*>& getCowInventory() const;

  void dropOffCow();

  void dropOffCow(const std::string& cowID);

};
