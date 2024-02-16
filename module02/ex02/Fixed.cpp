#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int integer) : value(integer << fractionalBits) {}

Fixed::Fixed(const float floating)
    : value(roundf(floating * (1 << fractionalBits))) {}

Fixed::Fixed(const Fixed &other) { (*this) = other; }

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    this->value = other.value;
  }
  return *this;
}

int Fixed::getRawBits(void) const { return this->value; }

void Fixed::setRawBits(int const raw) { this->value = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(this->value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const { return this->value >> fractionalBits; }

bool Fixed::operator>(const Fixed &other) const {
  return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
  return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
  return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  if (other.value == 0) {
    throw std::runtime_error("Division by zero.");
  }
  return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
  this->value++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  operator++();
  return temp;
}

Fixed &Fixed::operator--() {
  this->value--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  operator--();
  return temp;
}

Fixed &Fixed::min(Fixed &first, Fixed &second) {
  return first < second ? first : second;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second) {
  return first < second ? first : second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
  return first > second ? first : second;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second) {
  return first > second ? first : second;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
