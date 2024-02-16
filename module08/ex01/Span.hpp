#include <iostream>
#include <list>

class Span {
private:
  std::list<int> _list;
  unsigned int _n;

  Span(void);

public:
  Span(unsigned int);
  Span(const Span &);
  ~Span(void);

  Span &operator=(const Span &);
  void addNumber(int);
  void addNumber(std::list<int>::const_iterator,
                 std::list<int>::const_iterator);
  unsigned int longestSpan(void) const;
  unsigned int shortestSpan(void) const;

  const std::list<int> *getList(void) const;
};

std::ostream &operator<<(std::ostream &, const Span &);
