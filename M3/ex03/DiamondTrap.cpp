#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
: FragTrap(name + "_clap_name"),    // construit le ClapTrap côté Frag
  ScavTrap(name + "_clap_name"),    // construit le ClapTrap côté Scav
  _name(name)
{
    _hitPoints = 100; // Valeur
    _energyPoints = 50; // 50
    _attackDamage = 30; // 30

    std::cout << "DiamondTrap " << _name << " created." << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: FragTrap(other), ScavTrap(other), _name(other._name) {
	std::cout << "DiamondTrap " << _name << " copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target); // Utilise l'attaque de ScavTrap
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << ", and my ClapTrap name is " << FragTrap::getName() << "." << std::endl;
}

/*    ClapTrap
      /     \
 ScavTrap   FragTrap
      \     /
     DiamondTrap
*/