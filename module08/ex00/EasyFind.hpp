#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // Pour std::find
#include <exception> // Pour std::exception

class NotFoundException : public std::exception {
public:
  NotFoundException() {}

  virtual ~NotFoundException() throw() {}

  virtual const char* what() const throw() {
    return "Value not found in container";
  }
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end()) {
    throw NotFoundException();
  }
  return it;
}

#endif


