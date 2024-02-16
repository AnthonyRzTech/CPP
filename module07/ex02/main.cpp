#include "Array.hpp"
#include <iostream>

int main() {
  // Test default construction
  Array<int> defaultArray;
  std::cout << "Default array size: " << defaultArray.size() << std::endl;

  // Test construction with size
  Array<int> sizedArray(5);
  std::cout << "Sized array initial values: ";
  for (size_t i = 0; i < sizedArray.size(); ++i) {
    std::cout << sizedArray[i] << " ";
  }
  std::cout << "\n";

  // Test copy construction
  Array<int> copiedArray = sizedArray;
  copiedArray[2] = 42; // Modify the copy and check the original
  std::cout << "Original after copying and modifying copy: ";
  for (size_t i = 0; i < sizedArray.size(); ++i) {
    std::cout << sizedArray[i] << " ";
  }
  std::cout << "\n";

  // Test out-of-bounds access
  try {
    std::cout << "Accessing out-of-bounds: " << sizedArray[10] << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}
