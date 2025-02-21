/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:41:38 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/21 17:35:38 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

///////////////////////////////////////
// Initialization static _fractBits //
/////////////////////////////////////

const int Fixed::_fractBits = 8;

//////////////////////////////////////////////////
// Constructor Default & add-doc polymorphisme //
////////////////////////////////////////////////

Fixed::Fixed( void ): _rawBits( 0 ){};

Fixed::Fixed( const float nb )
{
	this->_rawBits = roundf( nb * (1 << Fixed::_fractBits));
}

Fixed::Fixed( const int nb )
{
	this->_rawBits = nb << Fixed::_fractBits;
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
}

/////////////////////////////////////
// Basic Functions members public //
///////////////////////////////////

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_rawBits) / (1 << Fixed::_fractBits));
}

int		Fixed::toInt( void ) const
{
	return (this->_rawBits >> Fixed::_fractBits);
}

//////////////////////////////////
// getter & setter for RawBits //
////////////////////////////////

int	Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}

//////////////////////////////////////
// Operator Overloading Assignment //
////////////////////////////////////

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	if (this != & rhs)
	{
		this->_rawBits = rhs.getRawBits();
	}
	return (*this);
}

///////////////////////////////////
// Operator Overloading Bitwise //
/////////////////////////////////

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

//////////////////////////////////////
// Operator Overloading Relational //
////////////////////////////////////

bool Fixed::operator<( Fixed const & rhs ) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>( Fixed const & rhs ) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator>=( Fixed const & rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=( Fixed const & rhs ) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==( Fixed const & rhs ) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=( Fixed const & rhs ) const
{
	return (this->toFloat() != rhs.toFloat());
}

/////////////////////////////////////////////
// Operator Overloading Binary Arithmetic //
///////////////////////////////////////////

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	return Fixed( this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	return Fixed( this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	return Fixed( this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	if (rhs.getRawBits() == 0)
	{
		std::cerr << "I cant divide with zero." << std::endl;
		return Fixed(0);
	}
	return Fixed( this->toFloat() / rhs.toFloat());
}

////////////////////////////////////////////
// Operator Overloading Unary Arithmetic //
//////////////////////////////////////////

Fixed &	Fixed::operator++( void )
{
	this->_rawBits += 1;
	return (*this);
}

Fixed &	Fixed::operator--( void )
{
	this->_rawBits -= 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed cpy(*this);
	cpy._rawBits = this->_rawBits++;
	return (cpy);
}

Fixed	Fixed::operator--( int )
{
	Fixed cpy(*this);
	cpy._rawBits = this->_rawBits--;
	return (cpy);
}

////////////////////////////////
// Function static min & max //
//////////////////////////////


Fixed &	Fixed::min( Fixed & a, Fixed & b )
{
	if ( a.toFloat() <= b.toFloat())
		return ( a );
	return ( b );
}

const Fixed &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if ( a.toFloat() <= b.toFloat())
		return ( a );
	return ( b );
}
Fixed &	Fixed::max( Fixed & a, Fixed & b )
{
	if ( a.toFloat() >= b.toFloat())
		return ( a );
	return ( b );
}
const Fixed &	Fixed::max( Fixed const & a, Fixed const & b )
{
	if ( a.toFloat() >= b.toFloat())
		return ( a );
	return ( b );
}

/////////////////
// Destructor //
///////////////

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
}
