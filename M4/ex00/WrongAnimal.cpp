/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:55:46 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/02 15:32:46 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal( void ): type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor default called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ): type(type)
{
	std::cout << "WrongAnimal constructor ad-hoc polymorphism called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ): type(src.type)
{
	std::cout << "WrongAnimal copy constructor called on " << src.type << std::endl;
}

WrongAnimal &	WrongAnimal::operator=( const WrongAnimal & rhs )
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << this->type << ": ..." << std::endl;
}

