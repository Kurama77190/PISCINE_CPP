#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
    DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& other);

    void whoAmI();
	void attack(const std::string& target);

private:
    std::string _name;
};

#endif
