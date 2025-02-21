/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:41:38 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/21 14:44:37 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed( void ): _rawBits( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed( const float nb )
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf( nb * (1 << Fixed::_fractBits));
}

Fixed::Fixed( const int nb )
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = nb << Fixed::_fractBits;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != & rhs)
	{
		this->_rawBits = rhs.getRawBits();
	}
	return (*this);
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_rawBits) / (1 << Fixed::_fractBits));
}

int		Fixed::toInt( void ) const
{
	return (this->_rawBits >> Fixed::_fractBits);
}


std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}
