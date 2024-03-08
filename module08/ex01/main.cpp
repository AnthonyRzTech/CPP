#include "Span.hpp"
#include <ctime>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}


//int main(void)
//{
//	int maxnumb = 10000;
//	try
//	{
//		Span span(maxnumb);
//		std::vector<int> inputNumbers;
//		std::srand(std::time(0));
//		for(int i = 0; i < maxnumb; i++)
//		{
//			int randomnumber = std::rand();
//			inputNumbers.push_back(randomnumber);
//		}
//		span.addNumbers(inputNumbers.begin(), inputNumbers.end());
//		int max = *std::max_element(inputNumbers.begin(), inputNumbers.end());
//		int min = *std::min_element(inputNumbers.begin(), inputNumbers.end());
//		std::cout << "Max. value is: " << max << "; Min. value is: " << min << "; Diff is: " << max - min << std::endl;
//		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
//		std::cout << "Longest Span: " << span.longestSpan() << std::endl;
//	}
//	catch (const std::exception &ex)
//	{
//		std::cerr << "Error: " << ex.what() << std::endl;
//	}
//}

