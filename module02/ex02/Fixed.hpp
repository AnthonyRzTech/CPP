#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
  int value;
  static const int fractionalBits = 8;

public:
  Fixed();
  Fixed(const int integer);
  Fixed(const float floating);
  Fixed(const Fixed &other);
  ~Fixed();

  Fixed &operator=(const Fixed &other);
  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

  // Overload comparison operators
  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  // Overload arithmetic operators
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  // Increment and decrement operators
  Fixed &operator++();   // Pre-increment
  Fixed operator++(int); // Post-increment
  Fixed &operator--();   // Pre-decrement
  Fixed operator--(int); // Post-decrement

  // Static member functions for min and max
  static Fixed &min(Fixed &first, Fixed &second);
  static const Fixed &min(const Fixed &first, const Fixed &second);
  static Fixed &max(Fixed &first, Fixed &second);
  static const Fixed &max(const Fixed &first, const Fixed &second);

  // Friend declaration for output stream operator
  friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
};

#endif
