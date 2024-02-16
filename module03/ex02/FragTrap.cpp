#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "FragTrap " << this->name << " is operational!" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->name << " is being shut down." << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << name << " requests high fives!" << std::endl;
}
