/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:30:42 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/31 17:05:38 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <new>
# include "Brain.hpp"

class Animal {

public:

	Animal( void );
	Animal( std::string );
	Animal( const Animal & src );
	virtual ~Animal();

	Animal &		operator=( const Animal & rhs);
	
	std::string		getType( void ) const;
	virtual	void	makeSound( void ) const = 0;

protected:

	std::string type;

};

#endif