/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:01:59 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/26 02:15:29 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include <limits>

# include "ClapTrap.hpp"


class ScavTrap: public ClapTrap {

public :

	ScavTrap( void );
	ScavTrap( std::string );
	ScavTrap( ScavTrap const & src );
	~ScavTrap( void );
	
	ScavTrap &		operator=( ScavTrap const & rhs );

	void			attack(const std::string& target);
	void			guardGate( void );

};

#endif