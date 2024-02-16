#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
  int evaluateExpression(const std::string &expression);

private:
  bool isOperator(const char &c) const;
  int performOperation(const int &a, const int &b, const char &op) const;
};

#endif // RPN_HPP
