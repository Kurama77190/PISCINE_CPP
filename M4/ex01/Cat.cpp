/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:34:08 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 00:51:23 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ): Animal()
{
	std::cout << "Cat constructor default called" << std::endl;
	this->type = "Cat";
}

Cat::Cat( std::string type )
{
	std::cout << "Cat constructor ad-hoc polymorphism called" << std::endl;
	this->type = type;
}

Cat::Cat( const Cat & src )
{
	std::cout << "Cat copy constructor called on " << src.type << std::endl;
	*this = src;
}

Cat &	Cat::operator=( const Cat & rhs )
{
	this->type = rhs.type;
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << this->type << ": meow meow" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
