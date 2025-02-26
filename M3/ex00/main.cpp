/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:13:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/26 01:56:49 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ( void )
{
	ClapTrap instance("Valentin");
	ClapTrap instance2;

	std::cout << "Hit points of " << instance.getName() << " : " << instance.getHitPoints() << std::endl;
	std::cout << "Hit points of " << instance2.getName() << " : " << instance2.getHitPoints() << std::endl;

	instance.attack(instance2.getName());
	instance2.takeDamage(instance.getAttackDamage());

	instance2.attack(instance.getName());
	instance.takeDamage(instance2.getAttackDamage());

	instance.attack("");
	instance.takeDamage(100);

	instance.beRepaired(2);
	instance2.beRepaired(1);

	std::cout << "Hit points of " << instance.getName() << " : " << instance.getHitPoints() << std::endl;
	std::cout << "Hit points of " << instance2.getName() << " : " << instance2.getHitPoints() << std::endl;

	return (0);
}
