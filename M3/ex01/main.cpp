/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:13:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/25 18:21:36 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap instance;
	ClapTrap instance2("Valentin");

	instance.guardGate();
	std::cout << instance.getHitPoints() << std::endl;
	std::cout << instance2.getHitPoints() << std::endl;
	instance.takeDamage(1);
	std::cout << instance.getHitPoints() << std::endl;
	instance2.takeDamage(1);
	std::cout << instance2.getHitPoints() << std::endl;
	
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
