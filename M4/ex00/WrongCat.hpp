/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:22:20 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/25 16:07:00 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

class WrongCat: public WrongAnimal {

public:

	WrongCat( void );
	WrongCat( std::string );
	WrongCat( const WrongCat & src );
	virtual ~WrongCat();

	WrongCat &		operator=( const WrongCat & rhs);

	void	makeSound( void ) const;

};

#endif