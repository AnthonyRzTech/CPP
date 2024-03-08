#include "Span.hpp"

Span::Span(void)
{
  _size = 0;
}

Span::Span(unsigned int n)
{
  _size = n;
}

Span::Span(Span const &copy)
{
  *this = copy;
}

Span &Span::operator=(Span const &copy)
{
  if (this != &copy)
  {
    _size = copy._size;
    _numbers = copy._numbers;
  }
  return (*this);

}

Span::~Span(void)
{

}

void Span::addNumber(int n)
{
  if (_numbers.size() >= _size)
    throw std::length_error("Maximum elements stored");
  _numbers.push_back(n);
}

void Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
  if (std::distance(begin, end) > _size)
    throw std::length_error("Amount of numbers to fill exceeds the allowed size");
  _numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan(void) const
{
  if (_numbers.size() <= 1)
    throw std::length_error("To few numbers filled, no span can be found");
  std::vector<int> sortedNumbers = _numbers;
  std::sort(sortedNumbers.begin(), sortedNumbers.end());
  int diff = std::numeric_limits<int>::max();
  for (size_t i = 1; i < sortedNumbers.size(); i++)
  {
    if ((sortedNumbers[i] - sortedNumbers[i - 1]) < diff)
      diff = (sortedNumbers[i] - sortedNumbers[i - 1]);
  }
  return (diff);
}

int Span::longestSpan(void) const
{
  if (_numbers.size() <= 1)
    throw std::length_error("To few numbers filled, no span can be found");
  return (*std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end()));
}
