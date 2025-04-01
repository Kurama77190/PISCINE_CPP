/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:18:51 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/25 18:22:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria( std::string const & type ): _type(type)
{
	std::cout << "AMateria constructor called." << std::endl;
}

AMateria::~AMateria( void )
{
	std::cout << "AMateria destructor called." << std::endl;
}

AMateria::AMateria( const AMateria & src ): _type(src._type)
{
	*this = src;
}

AMateria &	AMateria::operator=( const AMateria & rhs )
{
	this->_type = rhs._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	if (this->_type.compare("ice") == 0)
		std::cout << RED << "Ice : \"* shoots an ice bolt at " << target.getName() << "*\"" << RESET << std::endl;
	else if (this->_type.compare("cure") == 0)
		std::cout << RED << "Cure : \"* heals " << target.getName() << "'s wounds *\"" << RESET << std::endl;
	else
		std::cout << RED << " il n'y a pas de fonction use() parmis l'enfant: " << RESET <<  target.getName() << std::endl;
	return ;
}
