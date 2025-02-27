/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:16:43 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/28 00:23:05 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice: public AMateria {

public:
	
	Ice( void );
	Ice( const Ice & src );
	~Ice( void );

	Ice &	operator=(const Ice & rhs );
	Ice*	clone() const;
	void	use(ICharacter& target);
};
	