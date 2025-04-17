/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:45:00 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/16 14:40:47 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

Intern::Intern( void )
{}

Intern::Intern( const Intern & src )
{
	*this = src;
}

Intern::~Intern( void )
{}

Intern & Intern::operator=( Intern const & rhs )
{
	if (this != &rhs)
	{
		this->_formNames[0] = rhs._formNames[0];
		this->_formNames[1] = rhs._formNames[1];
		this->_formNames[2] = rhs._formNames[2];
		this->_formConstructors[0] = rhs._formConstructors[0];
		this->_formConstructors[1] = rhs._formConstructors[1];
		this->_formConstructors[2] = rhs._formConstructors[2];
	}
	return (*this);
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    this->_formNames[0] = "shrubbery creation";
    this->_formNames[1] = "robotomy request";
    this->_formNames[2] = "presidential pardon";

    this->_formConstructors[0] = &Intern::makeShrubberyCreationForm;
    this->_formConstructors[1] = &Intern::makeRobotomyRequestForm;
    this->_formConstructors[2] = &Intern::makePresidentialPardonForm;

    for (int i = 0; i < 3; i++)
	{
        if (formName == this->_formNames[i])
		{
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*(_formConstructors[i]))(target);
        }
    }
    throw FormNotFoundException();
	return (NULL);
}
