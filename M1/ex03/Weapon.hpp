/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:03:04 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/08 04:02:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class	Weapon{

public:

	std::string	getType( void ) const;
	void		setType( std::string weapon );

	Weapon( std::string weapon );
	~Weapon( void );

private:

	std::string _type;

};

#endif