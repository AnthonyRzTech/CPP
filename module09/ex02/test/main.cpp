#include "PmergeMe.hpp" // Ensure this includes your generic PmergeMe class definition
#include <chrono>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Error: No integers provided." << std::endl;
    return 1;
  }

  std::vector<int> inputNumbers;
  for (int i = 1; i < argc; ++i) {
    int number;
    std::istringstream iss(argv[i]);
    if (!(iss >> number) || number < 0) {
      std::cerr << "Error: Invalid input '" << argv[i]
                << "'. Positive integers only." << std::endl;
      return 1;
    }
    inputNumbers.push_back(number);
  }

  // Sorting and timing for std::vector
  std::cout << "Before sorting std::vector: ";
  for (int num : inputNumbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  auto startVector = std::chrono::high_resolution_clock::now();
  std::vector<int> vectorSorted =
      PmergeMe<std::vector<int>>::fordJohnsonSort(inputNumbers);
  auto endVector = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> vectorDuration =
      endVector - startVector;

  std::cout << "After sorting std::vector: ";
  for (int num : vectorSorted) {
    std::cout << num << " ";
  }
  std::cout << "\nTime for std::vector: " << vectorDuration.count() << " us\n"
            << std::endl;

  // Sorting and timing for std::deque
  std::deque<int> inputDeque(inputNumbers.begin(), inputNumbers.end());
  std::cout << "Before sorting std::deque: ";
  for (int num : inputDeque) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  auto startDeque = std::chrono::high_resolution_clock::now();
  std::deque<int> dequeSorted =
      PmergeMe<std::deque<int>>::fordJohnsonSort(inputDeque);
  auto endDeque = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> dequeDuration =
      endDeque - startDeque;

  std::cout << "After sorting std::deque: ";
  for (int num : dequeSorted) {
    std::cout << num << " ";
  }
  std::cout << "\nTime for std::deque: " << dequeDuration.count() << " us"
            << std::endl;

  return 0;
}
