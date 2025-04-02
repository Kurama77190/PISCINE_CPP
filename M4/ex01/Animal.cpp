/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:31:54 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/02 15:34:20 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal( void ): type("Animal")
{
	std::cout << "Animal constructor default called" << std::endl;
}

Animal::Animal( std::string type ): type(type)
{
	std::cout << "Animal constructor ad-hoc polymorphism called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal( const Animal & src ): type(src.type)
{
	std::cout << "Animal copy constructor called on " << src.type << std::endl;
}

Animal &	Animal::operator=( const Animal & rhs )
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}

void	Animal::makeSound( void ) const
{
	std::cout << this->type << ": ..." << std::endl;
}

