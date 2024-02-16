#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"

int main() {
  ClapTrap clapTrap("ClapTrap One");
  ScavTrap scavTrap("ScavTrap One");
  FragTrap fragTrap("FragTrap One");

  clapTrap.attack("an enemy");
  scavTrap.guardGate();
  fragTrap.highFivesGuys();

  return 0;
}
