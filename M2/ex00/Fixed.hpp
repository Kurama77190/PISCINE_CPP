/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:41:35 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/20 18:08:51 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <limits>

class Fixed {

public :

			Fixed( void ); // Canonical
			Fixed( Fixed const & src ); // Canonical
			~Fixed( void ); // Canonical

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	
	Fixed &	operator=( Fixed const & rhs ); // Canonical

private :

	int					_rawBits;
	static const int	_fractBits;
};



#endif
