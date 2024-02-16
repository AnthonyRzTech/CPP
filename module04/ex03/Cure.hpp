#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  // Constructors
  Cure(void);
  Cure(Cure const &src);
  ~Cure(void);

  // Operators
  Cure &operator=(Cure const &src);

  // Member Functions
  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif
