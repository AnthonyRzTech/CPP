#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>
// Constructors

Cure::Cure(void) : AMateria("cure") {
  std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src.type) {
  std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure(void) { std::cout << "Cure destructor called" << std::endl; }

// Operators

Cure &Cure::operator=(Cure const &src) {
  std::cout << "Cure assignation operator called" << std::endl;
  if (this == &src)
    return (*this);
  return (*this);
}

AMateria *Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
