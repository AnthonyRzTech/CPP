#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
  std::string const _name;
  bool _isSigned;
  int const _signGrade;
  int const _executeGrade;

  void _checkGrades(int signGrade, int executeGrade);

public:
  Form();
  Form(Form const &other);
  Form(int signGrade, int executeGrade);
  Form(std::string const &name);
  Form(std::string const &name, int signGrade, int executeGrade);
  ~Form();

  Form &operator=(Form const &other);

  std::string const getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecuteGrade() const;

  void beSigned(Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, Form *form);
