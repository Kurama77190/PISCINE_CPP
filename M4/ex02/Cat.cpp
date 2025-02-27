/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:34:08 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 15:37:43 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ): Animal()
{
	std::cout << "Cat constructor default called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
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

void			Cat::setBrainIdeas( int indexTab, std::string idea )
{
	this->_brain->setIdeas(indexTab, idea);
}

std::string		Cat::getBrainIdeas( int indexTab ) const
{
	if (this->_brain->getIdeas(indexTab).empty())
		return ("null");
	return (this->_brain->getIdeas(indexTab));
}

void	Cat::makeSound( void ) const
{
	std::cout << this->type << ": meow meow" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}
