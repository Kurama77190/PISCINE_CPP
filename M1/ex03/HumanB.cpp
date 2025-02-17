/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:24:33 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/17 17:21:58 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ): _name(name), _weapon(NULL){}

HumanB::~HumanB( void ){}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}

void	HumanB::attack( void ) const
{
	std::cout << this->_name << " attacks with their ";
	if (this->_weapon)
	{
		std::cout << this->_weapon->getType();
	}	
	else
	{
		std::cout << "divin Fist";
	}
	std::cout << std::endl;
}

