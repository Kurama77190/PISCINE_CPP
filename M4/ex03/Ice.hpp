/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:16:43 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/31 13:37:22 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria {

public:
	
	Ice( void );
	Ice( const Ice & src );
	virtual ~Ice( void );

	Ice &	operator=(const Ice & rhs );
	Ice*	clone() const;
	void	use(ICharacter& target);
};

#endif