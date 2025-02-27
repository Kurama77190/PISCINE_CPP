/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:55:29 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 18:16:54 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <new>
# include <iostream>
# include "ICharacter.hpp"

class AMateria {

public:

AMateria( void );
AMateria( std::string const & type );
AMateria( const AMateria & src );
virtual ~AMateria( void );

AMateria &			operator=( const AMateria & rhs );

virtual AMateria* 	clone() const = 0;
std::string const & getType() const;
virtual void 		use(ICharacter& target);

protected:

std::string	_type;

};
