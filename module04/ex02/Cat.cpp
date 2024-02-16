#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) {
  type = "Cat";
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  Animal::operator=(other);
  return *this;
}

Cat::~Cat() {
  delete brain;
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }
