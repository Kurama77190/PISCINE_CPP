/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:11:40 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/25 15:42:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>void	swap(T &s1, T &s2)
{
	T tmp = s1;
	s1 = s2;
	s2 = tmp;
}

template<typename T>T		min(T s1, T s2) { return ((s1 < s2)? s1:s2); }

template<typename T>T		max(T s1, T s2) { return ((s1 > s2)? s1:s2); }

#endif