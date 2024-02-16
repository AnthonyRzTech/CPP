#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "ClapTrap " << this->name << " is born!\n";
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->name << " is destroyed.\n";
}

void ClapTrap::attack(const std::string &target) {
  if (energyPoints > 0 && hitPoints > 0) {
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << attackDamage << " points of damage!\n";
    energyPoints--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints > amount) {
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage!\n";
  } else {
    hitPoints = 0;
    std::cout << "ClapTrap " << name << " is out of hit points!\n";
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (energyPoints > 0) {
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount
              << " hit points!\n";
  }
}
