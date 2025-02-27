/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:16:43 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 18:43:20 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Ice: public AMateria {

public:
	
	Ice( void );
	Ice( std::string const & type );
	Ice( const Ice & src );
	~Ice( void );
	
	virtual Ice*	clone() const;
	virtual void	use(ICharacter& target);
};
	