/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 02:14:58 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/02 15:35:16 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain constructor default called" << std::endl;
}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain copy constructor called " << std::endl;
	*this = src;
}

Brain &	Brain::operator=( const Brain & rhs )
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdeas( int index ) const
{
	if ( index < 0 || index > 99 )
		return ("null");
	return (this->ideas[index]);
}

void		Brain::setIdeas( int index, std::string idea )
{
	if ( index < 0 || index > 99 )
		return ;
	this->ideas[index] = idea;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}