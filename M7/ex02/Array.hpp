/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:26:31 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/25 20:24:22 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# define BLUE "\033[34m"
# define RESET "\033[0m"
# define RED "\033[31m"

template<typename T> class Array {
public:

	Array( void );
	Array( unsigned int n ); // taille de l'array
	~Array( void );
	Array( const Array & src );
	Array & operator=( const Array & rhs );
	T & operator[]( unsigned int index );
	
	unsigned int	size( void ) const;


private:

	unsigned int	_size;
	T *				_array;

};

# include "Array.tpp"


#endif