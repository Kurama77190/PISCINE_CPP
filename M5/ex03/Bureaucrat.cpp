/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:14:38 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/17 17:48:32 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
  if (_grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (_grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
  if (_grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (_grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : _name(src._name), _grade(src._grade){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
  if (this != &rhs)
    this->_grade = rhs.getGrade();
  return *this;
}

std::string const Bureaucrat::getName() const
{
  return this->_name;
}

int Bureaucrat::getGrade() const
{
  return this->_grade;
}

void Bureaucrat::incrementGrade()
{
  if (this->_grade == 1)
    throw Bureaucrat::GradeTooHighException();
  this->_grade--;
}

void Bureaucrat::decrementGrade()
{
  if (this->_grade == 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade++;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
  return (o);
}

// new function

void Bureaucrat::signForm(AForm &form)
{
  try
  {
    form.beSigned(*this);
    std::cout << RED << this->getName() << " signed " << form.getName() << RESET
              << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << RED << this->getName() << " couldn't sign " << form.getName()
              << " because " << e.what() << RESET << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form)
{
  try
  {
    form.execute(*this);
    std::cout << RED << this->getName() << " executed " << form.getName() << RESET << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << RED<< this->getName() << " couldn't execute " << form.getName()
              << " because " << e.what() << RESET << std::endl;
  }
}
