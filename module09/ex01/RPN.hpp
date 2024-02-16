#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
  // Constructeur par défaut
  RPN() {}

  // Destructeur
  virtual ~RPN() {}

  // Constructeur de copie
  RPN(const RPN &other) {}

  // Opérateur d'affectation de copie
  RPN &operator=(const RPN &other) {
    // Dans un cas réel, vous devriez copier les attributs de 'other' dans
    // 'this'
    return *this;
  }

  // Méthode pour évaluer une expression en notation polonaise inversée
  int evaluateExpression(const std::string &expression);

private:
  bool isOperator(const char &c) const;
  int performOperation(const int &a, const int &b, const char &op) const;
};

#endif // RPN_HPP
