#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
// Constructors

AMateria::AMateria(void) {
  std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) {
  std::cout << "AMateria constructor called" << std::endl;
  this->type = type;
}

AMateria::~AMateria(void) {
  std::cout << "AMateria destructor called" << std::endl;
}

// Getters

std::string const &AMateria::getType() const { return (this->type); }

// Member Functions

void AMateria::use(ICharacter &target) { (void)target; }
