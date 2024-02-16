#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
  BitcoinExchange(const std::string &dbPath);
  float getPriceOnDate(const std::string &date, float value) const;

private:
  std::map<std::string, float> prices;
  void loadPrices(const std::string &dbPath);
};

#endif // BITCOINEXCHANGE_HPP
