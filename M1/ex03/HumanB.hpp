	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:22:59 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/08 03:51:10 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB{

public:

	HumanB( std::string name );
	~HumanB( void );

	void	setWeapon( Weapon& weapon );
	void	attack( void ) const;

private:

	std::string _name;
	Weapon*		_weapon;

};

#endif