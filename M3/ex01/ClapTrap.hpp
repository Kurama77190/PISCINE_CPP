/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:06:15 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/24 19:28:37 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <limits>

# include "ScavTrap.hpp"

class ClapTrap {

public:

	ClapTrap( void );
	ClapTrap ( std::string );
	ClapTrap ( ClapTrap const & src );
	~ClapTrap( void );

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	unsigned int	getAttackDamage( void );
	unsigned int	getHitPoints( void );
	unsigned int	getEnergyPoints( void );
	std::string		getName( void );

	ClapTrap &	operator=( ClapTrap const & rhs );
	
	ScavTrap		x;

private:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif
