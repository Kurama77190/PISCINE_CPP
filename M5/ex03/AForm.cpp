/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:20:38 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/15 17:38:43 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( std::string name, bool isSigned, int toSigne, int toExecute): _name(name),
_isSigned(isSigned), _requiredGradeToSign(toSigne), _requiredGradeToExecute(toExecute)
{
	if (toSigne < 1 || toExecute < 1)
		throw AForm::GradeTooHighException();
	else if (toSigne > 150 || toExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm ( const AForm & src )
: _name(src._name), _isSigned(src._isSigned), _requiredGradeToSign(src._requiredGradeToSign), _requiredGradeToExecute(src._requiredGradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm( void )
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm & AForm::operator=( AForm const & rhs )
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

std::string	AForm::getName( void ) const
{
	return (this->_name);
}

bool	AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int		AForm::getRequiredGradeToSign( void ) const
{
	return (this->_requiredGradeToSign);
}

int		AForm::getRequiredGradeToExecute( void ) const
{
	return (this->_requiredGradeToExecute);
}

void	AForm::beSigned(const Bureaucrat & src)
{
	if (src.getGrade() > this->_requiredGradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

std::ostream & operator<<( std::ostream & o, AForm const & i )
{
	o << RED << "AForm name: " << i.getName() << ", is signed: " << i.getIsSigned() << ", required grade to sign: " << i.getRequiredGradeToSign() << ", required grade to execute: " << i.getRequiredGradeToExecute() << RESET << std::endl;
	return o;
}
