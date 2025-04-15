/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:10:02 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/15 19:52:26 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << GREEN << "=========== TEST BUREAUCRAT CREATION =========== " << RESET << std::endl;

    Bureaucrat john("John", 5);
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 150);
    Bureaucrat highRank("HighRank", 1);
    Bureaucrat lowRank("LowRank", 150);

    std::cout << john << std::endl;
    std::cout << bob << std::endl;
    std::cout << alice << std::endl;
    std::cout << highRank << std::endl;
    std::cout << lowRank << std::endl;

    std::cout << GREEN << "=========== TEST FORM CREATION =========== " << RESET << std::endl;

    PresidentialPardonForm pardonForm("Alice");
    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Bob");

    std::cout << pardonForm << std::endl;
    std::cout << shrubberyForm << std::endl;
    std::cout << robotomyForm << std::endl;

    std::cout << GREEN << "=========== TEST SIGNATURE =========== " << RESET << std::endl;

    bob.signForm(pardonForm); // Should fail (grade too low)
    john.signForm(pardonForm); // Should succeed
    alice.signForm(shrubberyForm); // Should succeed
    bob.signForm(robotomyForm); // Should succeed

    std::cout << GREEN << "=========== TEST EXECUTION =========== " << RESET << std::endl;

    alice.executeForm(shrubberyForm); // Should succeed (ASCII trees)
    john.executeForm(pardonForm); // Should succeed (pardon Alice)
    bob.executeForm(robotomyForm); // Should succeed or fail randomly (robotomy)

    std::cout << GREEN << "=========== TEST INTERN =========== " << RESET << std::endl;

    Intern intern;

    // Test: Intern creates forms
    AForm *form1 = intern.makeForm("shrubbery creation", "Garden");
    AForm *form2 = intern.makeForm("robotomy request", "Bender");
    AForm *form3 = intern.makeForm("presidential pardon", "Marvin");

    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;

    // Test: Intern creates an invalid form
    try {
        AForm *invalidForm = intern.makeForm("invalid form", "Target");
        delete invalidForm; // Just in case it somehow succeeds
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    // Test: Signing and executing forms created by the intern
    highRank.signForm(*form1); // Should succeed
    highRank.executeForm(*form1); // Should succeed (ASCII trees)

    bob.signForm(*form2); // Should succeed
    bob.executeForm(*form2); // Should succeed or fail randomly (robotomy)

    john.signForm(*form3); // Should succeed
    john.executeForm(*form3); // Should succeed (pardon Marvin)

    // Clean up
    delete form1;
    delete form2;
    delete form3;

    return 0;
}
