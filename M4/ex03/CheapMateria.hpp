/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheapMateria.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:16:43 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/31 13:37:10 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHEAP_MATERIA_HPP
# define CHEAP_MATERIA_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class CheapMateria: public AMateria {

public:
	
	CheapMateria( void );
	CheapMateria( const CheapMateria & src );
	virtual ~CheapMateria( void );

	CheapMateria &	operator=(const CheapMateria & rhs );
	CheapMateria*	clone() const;
};

#endif