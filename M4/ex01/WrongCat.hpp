/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:22:20 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 00:47:34 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Animal.hpp"
# include <string>
# include <iostream>

class WrongCat: public Animal {

public:

	WrongCat( void );
	WrongCat( std::string );
	WrongCat( const WrongCat & src );
	virtual ~WrongCat();

	WrongCat &		operator=( const WrongCat & rhs);

	virtual void	makeSound( void ) const;

};

#endif