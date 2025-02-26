/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:13:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/26 01:10:14 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap instance;
	ClapTrap instance2("Valentin");
	
	std::cout << "Hit points of " << instance.getName() << " : " << instance.getHitPoints() << std::endl;
	std::cout << "Hit points of " << instance2.getName() << " : " << instance2.getHitPoints() << std::endl;

	instance.guardGate();

	instance2.attack(instance.getName());
	instance.takeDamage(instance2.getAttackDamage());

	instance.attack(instance2.getName());
	instance2.takeDamage(instance.getAttackDamage());

	std::cout << "Hit points of " << instance.getName() << " : " << instance.getHitPoints() << std::endl;
	std::cout << "Hit points of " << instance2.getName() << " : " << instance2.getHitPoints() << std::endl;
	
	instance2.beRepaired(1);

	return (0);
}
