/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:30 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/26 02:46:00 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap()
{
	std::cout << "FragTrap constructor default called." << std::endl;
	this->_name = "samy";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}
FragTrap::FragTrap( std::string name ): ClapTrap(name)
{
	std::cout << "FragTrap constructor had-hoc polymorphism called." << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( FragTrap const & src )
{
	*this = src;
}

FragTrap &		FragTrap::operator=( FragTrap const & rhs )
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_attackDamage = rhs._attackDamage;
	_energyPoints = rhs._energyPoints;
	return (*this);
}

void			FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0 || target.empty())
	{
		if (this->_hitPoints == 0)
			std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
		else if (target.empty())
			std::cout << "FragTrap " << this->_name << " cannot attack anyone" << std::endl;
		else
			std::cout << "FragTrap " << this->_name << " doesn't have energy points" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name <<  " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void			FragTrap::highFivesGuys( void )
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0)
	{
		if (_hitPoints == 0)
			std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
		else
			std::cout << "FragTrap " << this->_name << " doesn't have energy points" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " wants high fives his mates." << std::endl;
	this->_energyPoints--;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap desctructor called." << std::endl;
}
