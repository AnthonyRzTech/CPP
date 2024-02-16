#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  std::cout << "ScavTrap " << this->name << " enters the battlefield!"
            << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->name << " is signing off." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (energyPoints > 0 && hitPoints > 0) {
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
              << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
  }
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << name << " is now in Gate Keeper mode."
            << std::endl;
}
