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

  friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
};

#endif
