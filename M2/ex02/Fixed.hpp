/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:18:14 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/21 16:34:09 by sben-tay         ###   ########.fr       */
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
	Fixed( const float nb ); //  Ad-hoc Polymorphisme 
	Fixed( const int nb ); //  Ad-hoc Polymorphisme 
	Fixed( Fixed const & src ); // Canonical
	~Fixed( void ); // Canonical
	Fixed &	operator=( Fixed const & rhs ); // Canonical
	
	bool	operator>( Fixed const & rhs ) const; // new operator overloading
	bool	operator<( Fixed const & rhs ) const; // new operator overloading
	bool	operator>=( Fixed const & rhs ) const; // new operator overloading
	bool	operator<=( Fixed const & rhs ) const; // new operator overloading
	bool	operator==( Fixed const & rhs ) const; // new operator overloading
	bool	operator!=( Fixed const & rhs ) const; // new operator overloading

	Fixed	operator+( Fixed const & rhs ) const; // operator overloading
	Fixed	operator-( Fixed const & rhs ) const; // operator overloading
	Fixed	operator*( Fixed const & rhs ) const; // operator overloading
	Fixed	operator/( Fixed const & rhs ) const; // operator overloading
	
	Fixed &	operator++( void ); // new operator overloading
	Fixed &	operator--( void ); // new operator overloading
	Fixed	operator++( int ); // new operator overloading
	Fixed	operator--( int ); // new operator overloading
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	static	Fixed &			min( Fixed & a, Fixed & b );
	static const Fixed &	min(Fixed const & a, Fixed const & b);
	static Fixed &			max( Fixed & a, Fixed & b );
	static const Fixed &	max( Fixed const & a, Fixed const & b );
	
private :

	int					_rawBits;
	static const int	_fractBits;

};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif
