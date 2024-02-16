#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : value(integer << fractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floating)
    : value(roundf(floating * (1 << fractionalBits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  (*this) = other;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->value = other.getRawBits();
  }
  return *this;
}

int Fixed::getRawBits(void) const { return this->value; }

void Fixed::setRawBits(int const raw) { this->value = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const { return value >> fractionalBits; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
