/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:18:30 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/01 18:21:24 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"


Cure::Cure( void ): AMateria("cure")
{
	std::cout << "Cure constructor called." << std::endl;
}

Cure::~Cure( void )
{
	std::cout << "Cure destructor called." << std::endl;
}

Cure::Cure( const Cure & src ): AMateria(src)
{
}

Cure &	Cure::operator=( const Cure & rhs )
{
	if (this != &rhs)
		this->AMateria::operator=(rhs);
	return (*this);
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << RED << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;	
};