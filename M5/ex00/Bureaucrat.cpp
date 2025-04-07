/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:14:38 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/06 16:24:52 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << "Parameterized constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

std::string const Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << RED << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << RESET << std::endl;
	return o;
}

