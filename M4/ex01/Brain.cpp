/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 02:14:58 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 02:15:40 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain constructor default called" << std::endl;
	this->type = "Brain";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain copy constructor called on " << src.type << std::endl;
	*this = src;
}

Brain &	Brain::operator=( const Brain & rhs )
{
	this->type = rhs.type;
	return (*this);
}

std::string	Brain::getType( void ) const
{
	return (this->type);
}

void	Brain::makeSound( void ) const
{
	std::cout << this->type << ": ..." << std::endl;
}

