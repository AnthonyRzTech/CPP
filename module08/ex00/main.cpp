#include "EasyFind.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers;
  // Manual initialization
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(4);
  numbers.push_back(5);

  try {
    // Test with a value that exists
    std::vector<int>::iterator found = easyfind(numbers, 3);
    std::cout << "Found value " << *found << " in the container." << std::endl;

    // Test with a value that doesn't exist
    found = easyfind(numbers, 6);
    // If an exception is not thrown, this line will not execute
    std::cout << "Found value " << *found << " in the container." << std::endl;
  } catch (const NotFoundException &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
