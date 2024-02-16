#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm;

class RobotomyRequestForm : public AForm {
private:
  std::string const _target;

  RobotomyRequestForm();

public:
  RobotomyRequestForm(std::string const &target);
  RobotomyRequestForm(RobotomyRequestForm const &other);
  ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

  std::string getTarget() const;

  virtual void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *src);
