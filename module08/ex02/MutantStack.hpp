#pragma once

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <numeric>

template <typename T>
class MutantStack : public std::stack<T>
{
	public: 

	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack(void) {}

	MutantStack(MutantStack const &copy)
	{
		*this = copy;
	}

	MutantStack &operator=(MutantStack const &copy)
	{
		if (this == &copy)
			return (*this);
		return (*this);	
	}

	~MutantStack(void) {}

	iterator begin()
	{
		return (std::stack<T>::c.begin());
	}

	iterator end()
	{
		return (std::stack<T>::c.end());
	}
};
