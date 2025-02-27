/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:36:22 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 00:52:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ): Animal()
{
	std::cout << "Dog constructor default called" << std::endl;
	this->type = "Dog";
}


Dog::Dog( std::string type )
{
	std::cout << "Dog constructor ad-hoc polymorphism called" << std::endl;
	this->type = type;
}

Dog::Dog( const Dog & src )
{
	std::cout << "Dog copy constructor called on " << src.type << std::endl;
	*this = src;
}

Dog &	Dog::operator=( const Dog & rhs )
{
	this->type = rhs.type;
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << this->type << ": Woaf Woaf" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
