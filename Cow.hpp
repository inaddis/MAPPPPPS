#ifndef COW_HPP
#define COW_HPP

#include <set>
#include <iostream>
#include <string>


class Cow {
  private: 
    std::string name;

  public: 
    Cow(const std::string& name) : name(name) {}

    ~Cow() {
      std::cout << name << " has been killed :/" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Cow& cow) {
      os << "Cow Name: " << cow.name;
      return os;
    }

    const std::string& getName() const {
      return name;
    }

    size_t getHash() const {
        size_t hash = 0;
        for (char c : name) {
            hash = hash * 31 + c;
        }
        return hash % 100; 
    }

};

#endif // COW_HPP
