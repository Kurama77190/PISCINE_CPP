/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:36:22 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/02 15:39:03 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ): Animal("Dog")
{
	std::cout << "Dog constructor default called" << std::endl;
	this->_brain = new Brain();
}


Dog::Dog( std::string type ): Animal(type)
{
	std::cout << "Dog constructor ad-hoc polymorphism called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( const Dog & src ): Animal(src.type)
{
	std::cout << "Dog copy constructor called on " << src.type << std::endl;
	this->_brain = new Brain(*src._brain);
}

Dog &	Dog::operator=( const Dog & rhs )
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);	
	}
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << this->type << ": Woaf Woaf" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}
