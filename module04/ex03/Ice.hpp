#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  // Constructors
  Ice(void);
  Ice(Ice const &src);
  ~Ice(void);

  // Operators
  Ice &operator=(Ice const &src);

  // Member Functions
  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif
