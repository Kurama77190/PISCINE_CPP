/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:30 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/24 19:26:39 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): _name("samy"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ScavTrap constructor default called." << std::endl;
}
ScavTrap::ScavTrap( std::string name ): _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ScavTrap constructor had-hoc polymorphisme called." << std::endl;
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
}

void			ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap desctructor called." << std::endl;
}