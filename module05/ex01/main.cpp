#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat a;         // Utilise le constructeur par défaut
    Bureaucrat b("Jean"); // Utilise le constructeur avec le nom
    Bureaucrat c(42);     // Utilise le constructeur avec le grade
    Bureaucrat d("Marie",
                 10); // Utilise le constructeur avec le nom et le grade
    Bureaucrat e = d; // Utilise le constructeur de copie

    std::cout << &a;
    std::cout << &b;
    std::cout << &c;
    std::cout << &d;
    std::cout << &e;

    // Test des exceptions
    Bureaucrat high("Too High", 0); // Devrait lancer GradeTooHighException
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << e.what() << std::endl;
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat low("Too Low", 151); // Devrait lancer GradeTooLowException
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << e.what() << std::endl;
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
