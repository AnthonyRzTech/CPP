#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>
// Constructors

Ice::Ice(void) : AMateria("ice") {
  std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src.type) {
  std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice(void) { std::cout << "Ice destructor called" << std::endl; }

// Operators

Ice &Ice::operator=(Ice const &src) {
  std::cout << "Ice assignation operator called" << std::endl;
  if (this == &src)
    return (*this);
  return (*this);
}

// Member Functions

AMateria *Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
