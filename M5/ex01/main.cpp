/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:17:21 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/16 15:12:55 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  std::cout << GREEN << "===========TEST OVERLOAD OSTREAM=========== " << RESET
            << std::endl;

  Bureaucrat *defaultBureaucrat = new Bureaucrat();
  Bureaucrat *paramBureaucrat = new Bureaucrat("John", 50);
  Bureaucrat *copyBureaucrat = new Bureaucrat(*paramBureaucrat);

  std::cout << *defaultBureaucrat << std::endl;
  std::cout << *paramBureaucrat << std::endl;
  std::cout << *copyBureaucrat << std::endl;

  std::cout
      << GREEN
      << "===========TEST INCREMENT/DECREMENT GRADE & EXCEPTION=========== "
      << RESET << std::endl;

  try {
    paramBureaucrat->incrementGrade();
    std::cout << *paramBureaucrat << std::endl;
    defaultBureaucrat->decrementGrade(); // <--- exception catched
    std::cout << *defaultBureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << GREEN << "===========TEST DEEP COPY=========== " << RESET
            << std::endl;

  *defaultBureaucrat = *paramBureaucrat; // <----- deep copy

  std::cout << *defaultBureaucrat << std::endl;
  std::cout << *paramBureaucrat << std::endl;

  defaultBureaucrat->incrementGrade();
  std::cout << *defaultBureaucrat << std::endl;
  std::cout << *paramBureaucrat << std::endl;

  std::cout << GREEN << "===========TEST FORM SIGNATURE=========== " << RESET
            << std::endl;

  try {
    Form formA("FormA", false, 40, 20); // Form requiring grade 40 to sign
    Form formB("FormB", false, 60, 30); // Form requiring grade 60 to sign

    std::cout << formA << std::endl;
    std::cout << formB << std::endl;

    paramBureaucrat->signForm(formA); // Should throw GradeTooLowException
    paramBureaucrat->signForm(formB); // Should succeed
  } catch (std::exception &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << GREEN << "===========TEST FORM EXCEPTIONS=========== " << RESET
            << std::endl;

  try {
    Form invalidFormHigh("InvalidFormHigh", false, 0,
                         20); // Invalid grade (too high)
  } catch (std::exception &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    Form invalidFormLow("InvalidFormLow", false, 151,
                        20); // Invalid grade (too low)
  } catch (std::exception &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  delete defaultBureaucrat;
  delete paramBureaucrat;
  delete copyBureaucrat;

  return 0;
}
