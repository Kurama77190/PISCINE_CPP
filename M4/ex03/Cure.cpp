/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:18:30 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 18:39:32 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( std::string const & type ): AMateria()
{
	std::cout << "Cure constructor ad-hoc polymorphism called." << std::endl;
	this->_type = type;
}

Cure::~Cure( void )
{
	std::cout << "Cure destructor called." << std::endl;
}


Cure* Cure::clone() const
{
	Cure* cpy = new Cure(this->_type);
	return (cpy);
}

void Cure::use(ICharacter& target)
{};