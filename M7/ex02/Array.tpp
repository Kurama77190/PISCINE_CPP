/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:26:02 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/25 20:07:47 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "Array.hpp"

/* if you want to erase all error, uncomment top line
but you can't compile that program; enjoy =) */

template<typename T>Array<T>::Array( void ): _size(0), _array(NULL) {}

template<typename T>Array<T>::Array( unsigned int n ): _size(n), _array(new T[_size])
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = T();
}

template<typename T>Array<T>::~Array( void ) { delete [] _array; }

template<typename T>unsigned int Array<T>::size( void ) const { return _size; }

template<typename T>Array<T>::Array( const Array & src ): _size(src._size), _array(NULL)
{
	*this = src;
}

template<typename T>Array<T> &Array<T>::operator=( const Array & rhs )
{
    if (this != &rhs)
    {
        T *tempArray = new T[rhs._size];

        for (unsigned int i = 0; i < rhs._size; i++)
            tempArray[i] = rhs._array[i];

		if (_array)
        	delete[] _array;

        // Mettre à jour les membres de l'objet
        _array = tempArray;
        _size = rhs._size;
    }
    return *this;
}


template<typename T>T &Array<T>::operator[]( unsigned int index )
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

