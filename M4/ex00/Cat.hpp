/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:34:05 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/31 13:39:06 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>
# include <iostream>

class Cat: public Animal {

public:

	Cat( void );
	Cat( std::string );
	Cat( const Cat & src );
	~Cat();

	Cat &		operator=( const Cat & rhs);

	virtual void	makeSound( void ) const;

};



#endif