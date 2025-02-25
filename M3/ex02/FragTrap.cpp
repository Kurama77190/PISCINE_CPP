/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:30 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/25 19:04:12 by sben-tay         ###   ########.fr       */
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
	std::cout << "FragTrap constructor had-hoc polymorphisme called." << std::endl;
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

void			FragTrap::highFivesGuys( void )
{
	std::cout << this->_name << "wants high fives his mates." << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap desctructor called." << std::endl;
}
