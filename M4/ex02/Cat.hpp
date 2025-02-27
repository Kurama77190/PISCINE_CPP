/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:34:05 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 14:47:07 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Cat: public Animal {

public:

	Cat( void );
	Cat( std::string );
	Cat( const Cat & src );
	virtual ~Cat();

	Cat &		operator=( const Cat & rhs);

	void			makeSound( void ) const;
	void			setBrainIdeas( int indexTab, std::string idea );
	std::string		getBrainIdeas( int indexTab ) const;
	

private:

	Brain*	_brain;

};



#endif