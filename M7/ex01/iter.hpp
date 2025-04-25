/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:44:45 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/25 20:24:09 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# define BLUE "\033[34m"
# define RESET "\033[0m"

# include <iostream>

template<typename T>void	printElement(T i)
{
	std::cout << i << " ";
}

template<typename T, typename T1, typename T2>void	iter(T *array, T1 length, T2 func)
{
	for (T1 i = 0; i < length; i++)
		func(array[i]);
}




#endif