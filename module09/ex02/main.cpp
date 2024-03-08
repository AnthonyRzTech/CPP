#include "PmergeMe.hpp"


int	main(int argc, char *argv[])
{
	try {
		if (argc - 1 < 1)
			throw std::runtime_error("Error");

		PmergeMe	pm;
		pm.sort(argc, argv);
	} catch (std::exception &e) {

		std::cerr << e.what() << std::endl;
		return 1;

	}

	return 0;
}
