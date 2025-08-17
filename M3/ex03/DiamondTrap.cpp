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
    // Fix des stats selon le sujet :
    // HP  et AD  viennent de FragTrap
    // EP  vient de ScavTrap
    FragTrap::_hitPoints    = 100;              // ou FragTrap::_hitPoints (déjà 100)
    ScavTrap::_energyPoints = 50;               // ou ScavTrap::_energyPoints (déjà 50)
    FragTrap::_attackDamage = 30;               // ou FragTrap::_attackDamage (déjà 30)

    std::cout << "DiamondTrap " << _name << " created.\n";
}


DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: FragTrap(other), ScavTrap(other), _name(other._name) {
	std::cout << "DiamondTrap " << _name << " copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target) {
    std::cout << "DiamondTrap " << _name << " attacks " << target << "!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << ", and my ClapTrap name is " << FragTrap::getName() << "." << std::endl;
}

