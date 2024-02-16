#include "Iter.hpp"
#include <iostream>

// Example function to be used with iter
template <typename T> void printElement(const T &element) {
  std::cout << element << std::endl;
}

// Specialized function for int type, showcasing how to handle different types
void incrementInt(int &element) { element++; }

int main() {
  // Test with an array of integers
  int intArray[] = {1, 2, 3, 4, 5};
  size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

  std::cout << "Original int array:" << std::endl;
  iter(intArray, intArrayLength, printElement);

  // Test with an array of strings
  std::string strArray[] = {"Hello", "World", "Template", "Function"};
  size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

  std::cout << "\nString array:" << std::endl;
  iter(strArray, strArrayLength, printElement);

  return 0;
}
