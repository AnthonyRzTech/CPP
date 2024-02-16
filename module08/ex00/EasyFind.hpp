#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // For std::find
#include <exception> // For std::exception

// Custom exception for when the value is not found
class NotFoundException : public std::exception {
public:
  const char *what() const throw() { return "Value not found in container"; }
};

// Function template easyfind
template <typename T> typename T::iterator easyfind(T &container, int value) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), value);
  if (it == container.end()) {
    throw NotFoundException();
  }
  return it;
}

#endif
