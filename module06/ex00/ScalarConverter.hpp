#pragma once

#include <string>

#define NAN_INF 1
#define ERROR 2
#define CHAR 3
#define INT 4
#define FLOAT 5
#define DOUBLE 6

#define RED "\033[31m"
#define SIGNAL "+-"
#define DIGIT_SET "+-0123456789"
#define DOUBLE_SET "+-0123456789."
#define FLOAT_SET "+-0123456789.f"

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &other);
  ScalarConverter &operator=(ScalarConverter const &other);
  ~ScalarConverter();

  static int parseInput(std::string const &input);

  static void fromChar(int type, std::string const &input);
  static void fromInt(int type, std::string const &input);
  static void fromFloat(int type, std::string const &input);
  static void fromDouble(int type, std::string const &input);

  static void print(int type, std::string const &input, char c, int i, float f,
                    double d);

public:
  static void convert(std::string const &input);
};
