/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 05:38:40 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/16 15:13:29 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

#define RED "\033[31m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

class AForm;

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  Bureaucrat(Bureaucrat const &src);
  ~Bureaucrat();

  Bureaucrat &operator=(Bureaucrat const &rhs);

  std::string const getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();
  void signForm(AForm &form);

  void executeForm(AForm const &form);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too high!"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too low!"; }
  };

private:
  const std::string _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif