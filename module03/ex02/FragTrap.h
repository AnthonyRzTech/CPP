#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
public:
  FragTrap(std::string name);
  ~FragTrap();

  void highFivesGuys(void);
};

#endif
