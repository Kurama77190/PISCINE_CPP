#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
public:
  Form(std::string name, bool isSigned, int toSigne, int Execute);
  Form(const Form &src);
  ~Form(void);
  Form &operator=(Form const &rhs);

  std::string getName(void) const;
  bool getIsSigned(void) const;
  int getRequiredGradeToSign(void) const;
  int getRequiredGradeToExecute(void) const;

  void beSigned(const Bureaucrat &src);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too high!"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Grade is too low!"; }
  };

private:
  const std::string _name;
  bool _isSigned;
  const int _requiredGradeToSign;
  const int _requiredGradeToExecute;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif