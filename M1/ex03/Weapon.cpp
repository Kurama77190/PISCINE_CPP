/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:13:02 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/08 04:02:22 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string weapon ) : _type(weapon){}

Weapon::~Weapon( void ){}

std::string	Weapon::getType( void ) const{
	return (this->_type);
}

void	Weapon::setType( std::string weapon ){
	this->_type = weapon;
}

