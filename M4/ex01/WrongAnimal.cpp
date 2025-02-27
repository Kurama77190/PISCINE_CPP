/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:55:46 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 00:55:58 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal( void )
{
	std::cout << "WrongAnimal constructor default called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( std::string type )
{
	std::cout << "WrongAnimal constructor ad-hoc polymorphism called" << std::endl;
	this->type = type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	std::cout << "WrongAnimal copy constructor called on " << src.type << std::endl;
	*this = src;
}

WrongAnimal &	WrongAnimal::operator=( const WrongAnimal & rhs )
{
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

