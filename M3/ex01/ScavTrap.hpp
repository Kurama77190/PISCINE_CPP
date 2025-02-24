/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:01:59 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/24 19:09:22 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include <limits>

class ScavTrap {

public :

	ScavTrap( void );
	ScavTrap( std::string );
	ScavTrap( ScavTrap const & src );
	~ScavTrap( void );
	
	ScavTrap &		operator=( ScavTrap const & rhs );
	void			guardGate( void );


private :

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif