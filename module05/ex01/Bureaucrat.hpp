#pragma once

#include "Form.hpp"
#include <iostream>
#include <string>

class Form;

class Bureaucrat {
private:
  std::string const _name;
  size_t _grade;

  void _setGrade(int grade);

public:
  Bureaucrat();
  Bureaucrat(std::string const &name);
  Bureaucrat(int grade);
  Bureaucrat(std::string const &name, int grade);
  Bureaucrat(Bureaucrat const &other);
  ~Bureaucrat();

  Bureaucrat &operator=(Bureaucrat const &other);

  std::string const getName() const;
  size_t getGrade() const;

  void incrementGrade();
  void decrementGrade();
  void signForm(Form &form);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat *bureaucrat);
