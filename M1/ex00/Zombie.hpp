/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:22:16 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/17 17:56:32 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	
	public:

	void	Announce( void );

	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );
	
	private:

	std::string	name;

};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif
