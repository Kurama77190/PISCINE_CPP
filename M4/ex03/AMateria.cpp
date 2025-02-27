/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:18:51 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 18:25:36 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ): _type("none")
{
	std::cout << "AMateria constructor default called." << std::endl;
}

AMateria::AMateria( std::string const & type ): _type(type)
{
	std::cout << "AMateria constructor ad-hoc polymorphism called." << std::endl;
}

AMateria::AMateria( const AMateria & src )
{
	*this = src;
}

AMateria &	AMateria::operator=( const AMateria & rhs )
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria( void )
{
	std::cout << "AMateria destructor default called." << std::endl;
};

std::string const & AMateria::getType() const
{
	return (this->_type);
}

// virtual void AMateria::use(ICharacter& target)
// {
	
// }
