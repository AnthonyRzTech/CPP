#include "ClapTrap.h"
#include "ScavTrap.h"

int main() {
  ClapTrap clapTrap("ClapTrap One");
  ScavTrap scavTrap("ScavTrap One");

  clapTrap.attack("an enemy");
  clapTrap.takeDamage(5);
  clapTrap.beRepaired(5);

  scavTrap.attack("another enemy");
  scavTrap.guardGate();

  return 0;
}
