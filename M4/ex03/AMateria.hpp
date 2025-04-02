/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:55:29 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/02 15:45:18 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <new>
# include <iostream>
# define RED     "\033[31m"
# define RESET   "\033[0m"

class ICharacter;

class AMateria {

public:

AMateria( std::string const & type );
AMateria( const AMateria & src );
virtual ~AMateria( void );

AMateria &			operator=( const AMateria & rhs );

std::string const & getType() const;
virtual AMateria* 	clone() const = 0;
virtual void 		use(ICharacter& target);

protected:

std::string	_type;

};

#endif