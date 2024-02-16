#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm;

class ShrubberyCreationForm : public AForm {
private:
  std::string const _target;

  ShrubberyCreationForm();

public:
  ShrubberyCreationForm(std::string const &target);
  ShrubberyCreationForm(ShrubberyCreationForm const &other);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

  std::string getTarget() const;

  virtual void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm *src);
