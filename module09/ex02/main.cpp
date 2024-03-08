#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: no arguments" << std::endl;
		return 1;
	}
	std::vector<unsigned int> vector;
	std::list<unsigned int> list;
	int	num;
	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		iss >> num;
		if (iss.fail() || !iss.eof() || num < 0)
		{
			std::cerr << "Error: invalid argument" << std::endl;
			return 1;
		}
		vector.push_back(num);
		list.push_back(num);
	}
	PmergeMe p(vector, list);
	p.mergeInsertionSort();
	return 0;
}
