#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _size(0)
{
	_vector.clear();
	_list.clear();
}

PmergeMe::PmergeMe(const std::vector<unsigned int> vector, const std::list<unsigned int> list) :  _size(vector.size()), _vector(vector), _list(list)
{
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
		_list = rhs._list;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	_vector.clear();
	_list.clear();
}

void PmergeMe::insertionSort(std::vector<unsigned int> &vector, unsigned int n)
{
	std::vector<unsigned int>::iterator it = vector.begin();
	for (; it != vector.end(); it++)
	{
		if (*it > n)
		{
			vector.insert(it, n);
			return;
		}
	}
	vector.push_back(n);
}

void PmergeMe::insertionSort(std::list<unsigned int> &list, unsigned int n)
{
	std::list<unsigned int>::iterator it = list.begin();
	for (; it != list.end(); it++)
	{
		if (*it > n)
		{
			list.insert(it, n);
			return;
		}
	}
	list.push_back(n);
}

void PmergeMe::vectorMergeInsertionSort()
{
	std::vector<unsigned int> small, large;
	unsigned int a, b, min, max;
	while (!_vector.empty())
	{
		a = _vector.back();
		_vector.pop_back();
		if (_vector.empty())
		{
			small.push_back(a);
			break;
		}
		b = _vector.back();
		_vector.pop_back();
		a > b ? (min = b, max = a) : (min = a, max = b);
		small.push_back(min);
		insertionSort(large, max);
	}
	std::vector<unsigned int>::iterator it = small.begin();
	for (; it != small.end(); it++)
		insertionSort(large, *it);
	_vector = large;
}

void PmergeMe::listMergeInsertionSort()
{
	std::list<unsigned int> small, large;
	unsigned int a, b, min, max;
	while (!_list.empty())
	{
		a = _list.back();
		_list.pop_back();
		if (_list.empty())
		{
			small.push_back(a);
			break;
		}
		b = _list.back();
		_list.pop_back();
		a > b ? (min = b, max = a) : (min = a, max = b);
		small.push_back(min);
		insertionSort(large, max);
	}
	std::list<unsigned int>::iterator it = small.begin();
	for (; it != small.end(); it++)
		insertionSort(large, *it);
	_list = large;
}

void PmergeMe::mergeInsertionSort()
{
	clock_t start, end;
	double vectorTime, listTime;
	std::cout << "Before: ";
	getVector();
	start = clock();
	vectorMergeInsertionSort();
	end = clock();
	vectorTime = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
	start = clock();
	listMergeInsertionSort();
	end = clock();
	listTime = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "After:  ";
	getVector();
	std::cout << "Time to process a range of " << _size << " elements with std::vector : " << vectorTime << " ms" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::list   : " << listTime << " ms" << std::endl;
}

void PmergeMe::getVector() const
{
	std::vector<unsigned int>::const_iterator it = _vector.begin();
	for (; it != _vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::getList() const
{
	std::list<unsigned int>::const_iterator it = _list.begin();
	for (; it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}