/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheapMateria.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:38:01 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/01 18:21:12 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CheapMateria.hpp"
	
CheapMateria::CheapMateria( void ): AMateria("CheapMateria")
{
	std::cout << "CheapMateria constructor called." << std::endl;
}

CheapMateria::~CheapMateria( void )
{
	std::cout << "CheapMateria destructor called." << std::endl;
}

CheapMateria::CheapMateria( const CheapMateria & src ): AMateria(src)
{
}

CheapMateria &	CheapMateria::operator=(const CheapMateria & rhs )
{
	if (this != &rhs)
		this->AMateria::operator=(rhs);
	return (*this);
}

CheapMateria* CheapMateria::clone() const
{
	return (new CheapMateria(*this));
}
