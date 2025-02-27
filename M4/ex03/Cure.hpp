/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:32 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/28 00:23:00 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <new>
# include "AMateria.hpp"

class Cure: public AMateria {

public:
	
	Cure( void );
	Cure( const Cure & src );
	~Cure( void );
	
	Cure &	operator=( const Cure & rhs );
	Cure*	clone() const;
	void	use(ICharacter& target);	

};
	