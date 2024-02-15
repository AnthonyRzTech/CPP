#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <stdexcept>

Span::Span(unsigned int N) : maxN(N) {}

void Span::addNumber(int number) {
  if (numbers.size() >= maxN) {
    throw std::length_error("Span is already full.");
  }
  numbers.push_back(number);
}

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
  while (begin != end) {
    addNumber(*begin++);
    if (numbers.size() >= maxN)
      break;
  }
}

int Span::shortestSpan() const {
  if (numbers.size() < 2) {
    throw std::logic_error("Not enough numbers to find a span.");
  }
  std::vector<int> sorted(numbers);
  std::sort(sorted.begin(), sorted.end());

  int minSpan = INT_MAX;
  for (size_t i = 1; i < sorted.size(); ++i) {
    int currentSpan = sorted[i] - sorted[i - 1];
    if (currentSpan < minSpan) {
      minSpan = currentSpan;
    }
  }
  return minSpan;
}

int Span::longestSpan() const {
  if (numbers.size() < 2) {
    throw std::logic_error("Not enough numbers to find a span.");
  }
  int minNumber = *std::min_element(numbers.begin(), numbers.end());
  int maxNumber = *std::max_element(numbers.begin(), numbers.end());
  return maxNumber - minNumber;
}
