#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
  // Constructeur
  explicit BitcoinExchange(const std::string &dbPath);

  // Destructeur
  ~BitcoinExchange();

  // Constructeur de copie
  BitcoinExchange(const BitcoinExchange &other);

  // Opérateur d'affectation de copie
  BitcoinExchange &operator=(const BitcoinExchange &other);

  // Méthode pour obtenir le prix à une date donnée
  float getPriceOnDate(const std::string &date, float value) const;

private:
  std::map<std::string, float> prices;
  void loadPrices(const std::string &dbPath);
};

#endif // BITCOINEXCHANGE_HPP
