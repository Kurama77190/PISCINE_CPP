/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:13:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/26 02:57:27 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ScavTrap instance;
	ClapTrap instance2("Valentin");
	FragTrap instance3("Diego");
	
	std::cout << "Hit points of " << instance.getName() << " : " << instance.getHitPoints() << std::endl;
	std::cout << "Hit points of " << instance2.getName() << " : " << instance2.getHitPoints() << std::endl;
	std::cout << "Hit points of " << instance3.getName() << " : " << instance3.getHitPoints() << std::endl;

	instance.guardGate();

	instance2.attack(instance.getName());
	instance.takeDamage(instance2.getAttackDamage());

	instance.attack(instance2.getName());
	instance2.takeDamage(instance.getAttackDamage());

	instance3.highFivesGuys();

	instance.attack(instance3.getName());
	instance3.takeDamage(instance.getAttackDamage());

	instance3.attack(instance.getName());
	instance.takeDamage(instance3.getAttackDamage());
	
	std::cout << "Hit points of " << instance.getName() << " : " << instance.getHitPoints() << std::endl;
	std::cout << "Hit points of " << instance3.getName() << " : " << instance3.getHitPoints() << std::endl;
	std::cout << "Hit points of " << instance2.getName() << " : " << instance2.getHitPoints() << std::endl;
	
	instance2.beRepaired(1);
	return (0);
}







// int main ( void )
// {
// 	ClapTrap instance("Valentin");
// 	ClapTrap instance2;
// 	instance.attack("samy");
// 	instance2.takeDamage(instance.getAttackDamage());
// 	std::cout << "ClapTrap samy have : " << instance2.getHitPoints() << " hit points !" << std::endl;
// 	instance2.beRepaired(1);
// 	std::cout << "ClapTrap samy have : " << instance2.getHitPoints() << " after Repaired !" << std::endl;
// 	std::cout << "Samy copy Valentin" << std::endl;
// 	instance2 = instance;
// 	std::cout << "ClapTrap samy have : " << instance2.getHitPoints() << " hit points !" << std::endl;
// 	std::cout << "samy rename-> " << instance2.getName() << " !" << std::endl;
// }
