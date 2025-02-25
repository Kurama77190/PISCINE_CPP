/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:30 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/25 18:26:13 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): ClapTrap()
{
	std::cout << "ScavTrap constructor default called." << std::endl;
	this->_name = "samy";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}
ScavTrap::ScavTrap( std::string name ): ClapTrap(name)
{
	std::cout << "ScavTrap constructor had-hoc polymorphisme called." << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap( ScavTrap const & src )
{
	*this = src;
}

ScavTrap &		ScavTrap::operator=( ScavTrap const & rhs )
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_attackDamage = rhs._attackDamage;
	_energyPoints = rhs._energyPoints;
	return (*this);
}

void			ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap desctructor called." << std::endl;
}
