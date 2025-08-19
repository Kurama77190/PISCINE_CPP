/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:13:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/08/19 16:08:23 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    DiamondTrap dt("Samy");

    dt.attack("target");
    std::cout << "Hit Points: " << dt.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << dt.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << dt.getAttackDamage() << std::endl;
    dt.whoAmI();
	
    return 0;
}
