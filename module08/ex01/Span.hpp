#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span
{
	private:
		std::vector<int> _numbers;
		unsigned int _size;

	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &copy);
		Span &operator=(Span const &copy);
		~Span(void);

		void addNumber(int n);
		void addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		int shortestSpan(void) const;
		int longestSpan(void) const;
};
