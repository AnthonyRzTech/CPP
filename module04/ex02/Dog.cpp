#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) {
  type = "Dog";
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  Animal::operator=(other);
  return *this;
}

Dog::~Dog() {
  delete brain;
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
