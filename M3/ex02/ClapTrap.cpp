/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:13:35 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/26 02:10:39 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): _name("samy"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor default called." << std::endl;
}

ClapTrap::ClapTrap ( std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor ad-hoc polymorphism called." << std::endl;
}

ClapTrap::ClapTrap ( ClapTrap const & src)
{
	*this = src;
}

ClapTrap &		ClapTrap::operator=( ClapTrap const & rhs)
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_attackDamage = rhs._attackDamage;
	_energyPoints = rhs._energyPoints;
	return (*this);
}

unsigned int	ClapTrap::getAttackDamage( void )
{
	return (this->_attackDamage);
}

unsigned int	ClapTrap::getHitPoints( void )
{
	return (this->_hitPoints);
}
unsigned int	ClapTrap::getEnergyPoints( void )
{
	return (this->_energyPoints);
}
std::string		ClapTrap::getName( void )
{
	return (this->_name);
}

void			ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0 || target.empty())
	{
		if (this->_hitPoints == 0)
			std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		else if (target.empty())
			std::cout << "ClapTrap " << this->_name << " cannot attack anyone" << std::endl;
		else
			std::cout << "ClapTrap " << this->_name << " doesn't have energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name <<  " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0)
	{
		if (_hitPoints == 0)
			std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		else
			std::cout << "ClapTrap " << this->_name << " doesn't have hit points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " lost : " << amount << " hit points."  << std::endl;
	for (int i = 0; i < amount; i++)
	{
		if (this->_hitPoints == 0)
			break ;
		else
			this->_hitPoints--;
	}
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0)
	{
		if (_hitPoints == 0)
			std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		else
			std::cout << "ClapTrap " << this->_name << " doesn't have energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " gains : " << amount << " hit points."  << std::endl;
	this->_energyPoints -= 1;
	this->_hitPoints += amount;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap desctructor called." << std::endl;
}