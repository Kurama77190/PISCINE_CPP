/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:30:04 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/21 17:36:47 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	// std::cout << Fixed::min( a, b ) << std::endl;

	// test pour la correction :

	// {
		// test des operateurs arithmetique
	// 	Fixed a(2);
	// 	Fixed const b( Fixed( 1 ) );
	// 	std::cout << " a * b = " << a * b << std::endl;
	// 	std::cout << " a + b = " << a + b << std::endl;
	// 	std::cout << " a - b = " << a - b << std::endl;
	// 	std::cout << " a / b = " << a / b << std::endl;
	// }
	return 0;
}
