/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:20:38 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/15 17:38:43 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string name, bool isSigned, int toSigne, int toExecute): _name(name),
_isSigned(isSigned), _requiredGradeToSign(toSigne), _requiredGradeToExecute(toExecute)
{
	if (toSigne < 1 || toExecute < 1)
		throw Form::GradeTooHighException();
	else if (toSigne > 150 || toExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form ( const Form & src )
: _name(src._name), _isSigned(src._isSigned), _requiredGradeToSign(src._requiredGradeToSign), _requiredGradeToExecute(src._requiredGradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form( void )
{
	std::cout << "Form destructor called" << std::endl;
}

Form & Form::operator=( Form const & rhs )
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

std::string	Form::getName( void ) const
{
	return (this->_name);
}

bool	Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int		Form::getRequiredGradeToSign( void ) const
{
	return (this->_requiredGradeToSign);
}

int		Form::getRequiredGradeToExecute( void ) const
{
	return (this->_requiredGradeToExecute);
}

void	Form::beSigned(const Bureaucrat & src)
{
	if (src.getGrade() > this->_requiredGradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}

std::ostream & operator<<( std::ostream & o, Form const & i )
{
	o << RED << "Form name: " << i.getName() << ", is signed: " << i.getIsSigned() << ", required grade to sign: " << i.getRequiredGradeToSign() << ", required grade to execute: " << i.getRequiredGradeToExecute() << RESET << std::endl;
	return o;
}
