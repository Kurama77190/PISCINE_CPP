/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:36:22 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/02 15:32:56 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ): Animal("Dog")
{
	std::cout << "Dog constructor default called" << std::endl;
}


Dog::Dog( std::string type ): Animal(type)
{
	std::cout << "Dog constructor ad-hoc polymorphism called" << std::endl;
}

Dog::Dog( const Dog & src ): Animal(src.type)
{
	std::cout << "Dog copy constructor called on " << src.type << std::endl;
}

Dog &	Dog::operator=( const Dog & rhs )
{
	if (this != &rhs)
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
