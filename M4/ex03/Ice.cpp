/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:38:01 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/28 00:13:14 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
	
Ice::Ice( void ): AMateria("ice")
{
	std::cout << "Ice constructor called." << std::endl;
}

Ice::~Ice( void )
{
	std::cout << "Ice destructor called." << std::endl;
}

Ice::Ice( const Ice & src ): AMateria(src)
{
}

Ice &	Ice::operator=(const Ice & rhs )
{
	this->AMateria::operator=(rhs);
	return (*this);
}

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{};