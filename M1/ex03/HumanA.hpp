/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:08:27 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/08 03:42:25 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class	HumanA{

public:

	HumanA( std::string name, Weapon& weapon );
	~HumanA( void );

	void	attack( void ) const;

private:

	std::string _name;
	Weapon&		_weapon;

};


#endif