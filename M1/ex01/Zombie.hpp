/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:45:37 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/17 17:59:37 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <limits>
# include <new>

class Zombie {

	public:

	void	setName( std::string name );
	void	announce( void );

			Zombie( void );
			~Zombie( void );

	private:

	std::string _name;

};

Zombie* zombieHorde( int N, std::string name );

#endif
