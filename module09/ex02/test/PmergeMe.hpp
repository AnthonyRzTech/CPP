// PmergeMe.hpp

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <deque>
#include <iterator>
#include <vector>

template <typename Container> class PmergeMe {
public:
  static void sort(Container &container);
  static void printVector(const std::vector<int> &v);
  static int binarySearchInsertPos(const std::vector<int> &arr, int start,
                                   int end, int key);
  static Container fordJohnsonSort(Container &input);
};

#endif // PMERGEME_HPP
