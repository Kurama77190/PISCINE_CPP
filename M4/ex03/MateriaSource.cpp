/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:09:11 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/01 18:27:30 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		this->array[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	*this = src;
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->array[i])
			delete this->array[i];
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->array[i])
				delete this->array[i];
			this->array[i] = NULL;
			if (rhs.array[i] != NULL)
				this->array[i] = rhs.array[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* src)
{
	if (src == NULL)
	{
		std::cerr << "src is null" << std::endl;
		return;
	}	

	for (int i = 0; i < 4; i++)
	{
		if (!this->array[i])
		{
			this->array[i] = src->clone();
			break;
		}
	}
	delete src;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if ( this->array[i] && this->array[i]->getType().compare(type) == 0)
			return (this->array[i]->clone());
	}
	return (NULL);
}
