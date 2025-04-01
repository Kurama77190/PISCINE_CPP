/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:32 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/31 13:37:16 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include <new>
# include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria {

public:
	
	Cure( void );
	Cure( const Cure & src );
	virtual ~Cure( void );
	
	Cure &	operator=( const Cure & rhs );
	Cure*	clone() const;
	void	use(ICharacter& target);	

};
	
#endif