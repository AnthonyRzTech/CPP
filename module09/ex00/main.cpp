#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

bool isValidValue(float value) { return value >= 0 && value <= 1000; }

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <bitcoin price db.csv> <input.txt>"
              << std::endl;
    return 1;
  }

  BitcoinExchange exchange(argv[1]);
  std::ifstream inputFile(argv[2]);
  if (!inputFile) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }

  std::string line, date;
  float value;
  getline(inputFile, line); // Skip header line

  while (getline(inputFile, line)) {
    std::istringstream iss(line);
    if (!(getline(iss >> std::ws, date, '|') && (iss >> value))) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    if (!isValidValue(value)) {
      std::cerr << "Error: not a positive number or too large a number => "
                << line << std::endl;
      continue;
    }

    try {
      float result = exchange.getPriceOnDate(date, value);
      std::cout << date << " => " << value << " = " << result << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return 0;
}
