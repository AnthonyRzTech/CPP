#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <time.h>
#include <string>
#include <sstream>

class PmergeMe
{
private:
	size_t _size;
	std::vector<unsigned int> _vector;
	std::list<unsigned int> _list;
public:
	PmergeMe();
	PmergeMe(const std::vector<unsigned int> vector, const std::list<unsigned int> list);
	PmergeMe(const PmergeMe &rhs);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();

	void insertionSort(std::vector<unsigned int> &vector, unsigned int n);
	void insertionSort(std::list<unsigned int> &list, unsigned int n);
	void vectorMergeInsertionSort();
	void listMergeInsertionSort();
	void mergeInsertionSort();

	void getVector() const;
	void getList() const;
};