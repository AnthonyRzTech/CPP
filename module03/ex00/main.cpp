#include "ClapTrap.hpp"

int main() {
  ClapTrap claptrap("CT-01");

  claptrap.attack("Target-01");
  claptrap.takeDamage(5);
  claptrap.beRepaired(5);

  return 0;
}
