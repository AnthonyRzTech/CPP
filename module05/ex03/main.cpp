#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    Intern intern;
    Bureaucrat bob("Bob", 1); // Un bureaucrate avec un grade élevé
    AForm *form;

    // Le stagiaire crée un formulaire
    form = intern.makeForm("shrubbery creation", "home");
    std::cout << form;

    // Bob signe le formulaire
    bob.signForm(*form);
    std::cout << form;

    // Bob exécute le formulaire
    bob.executeForm(*form);

    // Nettoyage
    delete form;

    // Tester avec un formulaire qui échoue à l'exécution
    form = intern.makeForm("robotomy request", "Marvin");
    std::cout << form;

    // Bob signe le formulaire
    bob.signForm(*form);
    std::cout << form;

    // Bob tente d'exécuter le formulaire, cela peut échouer aléatoirement
    bob.executeForm(*form);

    // Nettoyage
    delete form;
  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}
