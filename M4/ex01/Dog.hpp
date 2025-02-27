/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:35:29 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 00:47:29 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>
# include <iostream>

class Dog: public Animal {

public:

	Dog( void );
	Dog( std::string );
	Dog( const Dog & src );
	virtual ~Dog();

	Dog &		operator=( const Dog & rhs);

	virtual void	makeSound( void ) const;

};



#endif