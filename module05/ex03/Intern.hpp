#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class AForm;

class Intern {
public:
  Intern();
  Intern(Intern const &other);
  ~Intern();

  Intern &operator=(Intern const &other);

  AForm *makeForm(std::string const &form, std::string const &target);
};
