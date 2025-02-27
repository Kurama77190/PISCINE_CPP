/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:32 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 18:43:34 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <new>
# include "ICharacter.hpp"

class Cure: public AMateria {

public:
	
	Cure( void );
	Cure( const Cure & src );
	Cure( std::string const & type );
	~Cure( void );
	
	virtual Cure*	clone() const;
	virtual void	use(ICharacter& target);

};
	