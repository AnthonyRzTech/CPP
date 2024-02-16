#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
public:
  ScavTrap(std::string name);
  ~ScavTrap();

  void attack(const std::string &target);
  void guardGate();
};

#endif
