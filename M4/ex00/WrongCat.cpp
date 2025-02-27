/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:22:12 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 11:25:32 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ): WrongAnimal()
{
	std::cout << "WrongCat constructor default called" << std::endl;
	this->type = "Wrong Cat";
}

WrongCat::WrongCat( std::string type )
{
	std::cout << "WrongCat constructor ad-hoc polymorphism called" << std::endl;
	this->type = type;
}

WrongCat::WrongCat( const WrongCat & src )
{
	std::cout << "WrongCat copy constructor called on " << src.type << std::endl;
	*this = src;
}

WrongCat &	WrongCat::operator=( const WrongCat & rhs )
{
	this->type = rhs.type;
	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	std::cout << this->type << ": meow meow" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}
