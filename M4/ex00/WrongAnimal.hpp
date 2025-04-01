/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:54:53 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/31 13:39:43 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>
# include <new>

class WrongAnimal {

public:

	WrongAnimal( void );
	WrongAnimal( std::string );
	WrongAnimal( const WrongAnimal & src );
	virtual ~WrongAnimal();

	WrongAnimal &		operator=( const WrongAnimal & rhs);
	
	std::string		getType( void ) const;
	void			makeSound( void ) const;

protected:

	std::string type;

};

#endif