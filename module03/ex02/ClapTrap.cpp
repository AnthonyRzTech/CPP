#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "ClapTrap " << this->name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->name << " is destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (energyPoints > 0 && hitPoints > 0) {
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints > amount) {
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage!" << std::endl;
  } else {
    hitPoints = 0;
    std::cout << "ClapTrap " << name << " is out of hit points!" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (energyPoints > 0) {
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount
              << " hit points!" << std::endl;
  }
}
