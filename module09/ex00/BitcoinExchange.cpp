#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(const std::string &dbPath) {
  loadPrices(dbPath);
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadPrices(const std::string &dbPath) {
  // Use c_str() to convert std::string to const char*
  std::ifstream dbFile(dbPath.c_str());
  std::string line, date;
  float price;

  while (getline(dbFile, line)) {
    std::istringstream iss(line);
    if (getline(iss, date, ',') && (iss >> price)) {
      prices[date] = price;
    }
  }
}

float BitcoinExchange::getPriceOnDate(const std::string &date,
                                      float value) const {
  if (prices.empty()) {
    throw std::runtime_error("Error: Database is empty.");
  }

  std::map<std::string, float>::const_iterator it = prices.lower_bound(date);

  // If the date is past the last available date in the database
  if (it == prices.end()) {
    --it; // Use the last available date
  }
  // If the date is greater than the first date in the database but not found,
  // adjust the iterator to the closest lower date.
  else if (it != prices.begin() && it->first != date) {
    --it;
  }
  // If the iterator is at the beginning and the date is not found, it means the
  // date is before any available data.
  if (it->first > date) {
    throw std::runtime_error("Error: Date before the database start => " +
                             date);
  }

  return it->second * value;
}
