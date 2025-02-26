/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:01:59 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/26 02:38:31 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <limits>

# include "ClapTrap.hpp"


class FragTrap: public ClapTrap {

public :

	FragTrap( void );
	FragTrap( std::string );
	FragTrap( FragTrap const & src );
	~FragTrap( void );
	
	FragTrap &		operator=( FragTrap const & rhs );

	void			attack(const std::string& target);
	void			highFivesGuys( void );

};	

#endif