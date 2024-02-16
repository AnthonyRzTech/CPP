#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <stdexcept>

int RPN::evaluateExpression(const std::string &expression) {
  std::istringstream iss(expression);
  std::stack<int> operands;
  char token;

  while (iss >> token) {
    if (isdigit(token)) {
      operands.push(token - '0'); // Convert char digit to int
    } else if (isOperator(token)) {
      if (operands.size() < 2) {
        throw std::runtime_error("Error: Invalid expression");
      }
      int b = operands.top();
      operands.pop();
      int a = operands.top();
      operands.pop();
      operands.push(performOperation(a, b, token));
    } else {
      throw std::runtime_error("Error: Unknown token");
    }
  }

  if (operands.size() != 1) {
    throw std::runtime_error("Error: Invalid expression");
  }

  return operands.top();
}

bool RPN::isOperator(const char &c) const {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(const int &a, const int &b, const char &op) const {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    if (b == 0) {
      throw std::runtime_error("Error: Division by zero");
    }
    return a / b;
  default:
    throw std::runtime_error("Error: Unknown operation");
  }
}
