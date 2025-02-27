/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:18:51 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/28 00:21:33 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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
}
