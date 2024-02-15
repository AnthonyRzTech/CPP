#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
  std::vector<int> numbers;
  unsigned int maxN;

public:
  Span(unsigned int N);
  void addNumber(int number);
  template <typename Iterator> void addNumber(Iterator begin, Iterator end);
  int shortestSpan() const;
  int longestSpan() const;
};

#endif
