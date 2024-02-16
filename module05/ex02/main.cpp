#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
int main() {
  try {
    Bureaucrat jean("Jean", 5);
    PresidentialPardonForm form1("Marvin");
    RobotomyRequestForm form2("Trillian");
    ShrubberyCreationForm form3("Arthur");

    std::cout << &jean << &form1 << &form2 << &form3;

    jean.signForm(form1);
    jean.signForm(form2);
    jean.signForm(form3);

    jean.executeForm(form1);
    jean.executeForm(form2);
    jean.executeForm(form3);
  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}
