/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:41:35 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/20 18:46:57 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <limits>
# include <cmath>
class Fixed {

public :

			Fixed( void ); // Canonical
			Fixed( const float nb );
			Fixed( const int nb );
			Fixed( Fixed const & src ); // Canonical
			~Fixed( void ); // Canonical

	int		getRawBits( void ) const;
	// void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	
	Fixed &	operator=( Fixed const & rhs ); // Canonical

private :

	int					_rawBits;
	static const int	_fractBits;

};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif
