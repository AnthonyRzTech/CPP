#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

void printVector(const std::vector<int> &v) {
  for (int num : v) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

// Binary search to find the correct insertion position
int binarySearchInsertPos(const std::vector<int> &arr, int start, int end,
                          int key) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == key) {
      return mid + 1;
    } else if (arr[mid] < key) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return start;
}

// Main sorting function implementing the described algorithm
std::vector<int> fordJohnsonSort(std::vector<int> &input) {
  int n = input.size();
  if (n <= 1)
    return input;

  std::vector<int> largerElements;
  std::vector<std::pair<int, int>> pairs;

  // Step 1: Pairing and identifying larger elements
  for (int i = 0; i < n - 1; i += 2) {
    if (input[i] > input[i + 1]) {
      largerElements.push_back(input[i]);
      pairs.push_back({input[i + 1], input[i]});
    } else {
      largerElements.push_back(input[i + 1]);
      pairs.push_back({input[i], input[i + 1]});
    }
  }

  // Recursively sort the larger elements
  largerElements = fordJohnsonSort(largerElements);

  // Step 2: Insert paired smallest element of S at the beginning
  std::vector<int> sorted;
  if (!pairs.empty() && pairs[0].first != largerElements[0]) {
    sorted.push_back(
        pairs[0].first); // Assuming first pair contains the smallest
  }

  // Combine sorted larger elements back
  sorted.insert(sorted.end(), largerElements.begin(), largerElements.end());

  // Step 3: Insert remaining elements
  for (auto &p : pairs) {
    if (std::find(sorted.begin(), sorted.end(), p.first) == sorted.end()) {
      int pos = binarySearchInsertPos(sorted, 0, sorted.size() - 1, p.first);
      sorted.insert(sorted.begin() + pos, p.first);
    }
  }

  // Handling odd number case by inserting the last element
  if (n % 2 != 0) {
    int pos = binarySearchInsertPos(sorted, 0, sorted.size() - 1, input.back());
    sorted.insert(sorted.begin() + pos, input.back());
  }

  return sorted;
}
template class PmergeMe<std::vector<int>>;
template class PmergeMe<std::deque<int>>;
