/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:30 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/26 02:06:34 by sben-tay         ###   ########.fr       */
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
	std::cout << "ScavTrap constructor had-hoc polymorphism called." << std::endl;
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
	if (this->_energyPoints == 0 || this->_hitPoints == 0)
	{
		if (_hitPoints == 0)
			std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		else
			std::cout << "ClapTrap " << this->_name << " doesn't have energy points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
	this->_energyPoints--;
}

void			ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0 || target.empty())
	{
		if (this->_hitPoints == 0)
			std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
		else if (target.empty())
			std::cout << "ScavTrap " << this->_name << " cannot attack anyone" << std::endl;
		else
			std::cout << "ScavTrap " << this->_name << " doesn't have energy points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name <<  " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap desctructor called." << std::endl;
}
