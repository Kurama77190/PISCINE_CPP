/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:13:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/25 19:06:02 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main( void )
{
	ClapTrap instance;
	ScavTrap instance2("Valentin");
	FragTrap instance3("Diego");

	std::cout << "Samy HitPoints: " << instance.getHitPoints() << std::endl;
	std::cout << "Valentin HitPoints: " << instance2.getHitPoints() << std::endl;
	std::cout << "Diego HitPoints: " << instance3.getHitPoints() << std::endl;

	instance.takeDamage(2);
	instance2.takeDamage(2);
	instance3.takeDamage(0);

	std::cout << "Samy HitPoints: " << instance.getHitPoints() << std::endl;
	std::cout << "Valentin HitPoints: " << instance2.getHitPoints() << std::endl;
	std::cout << "Diego HitPoints: " << instance3.getHitPoints() << std::endl;
	
	instance2.guardGate();
	instance3.highFivesGuys();

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
