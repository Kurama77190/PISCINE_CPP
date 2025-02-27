/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:38:01 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 18:39:56 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( std::string const & type ): AMateria()
{
	std::cout << "Ice constructor ad-hoc polymorphism called." << std::endl;
	this->_type = type;
}

Ice::~Ice( void )
{
	std::cout << "Ice destructor called." << std::endl;
}


Ice* Ice::clone() const
{
	Ice* cpy = new Ice(this->_type);
	return (cpy);
}

void Ice::use(ICharacter& target)
{};