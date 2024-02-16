#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>

class PmergeMe {
public:
  PmergeMe();
  ~PmergeMe();

  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &);

  bool parseAndStoreNumbersInVec(int argc, char **argv);
  bool parseAndStoreNumbersInDeq(int argc, char **argv);
  void mergeInsertSortVec();
  void mergeInsertSortDeq();
  void printNumbersInVec();
  void printNumbersInDeq();
  int getVecSize();
  int getDeqSize();

private:
  std::vector<int> _vec;
  std::deque<int> _deq;
};
#endif
