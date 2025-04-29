/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:34:30 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/29 20:52:17 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <map>
# include <set>
# include <deque>
# include <algorithm>
# include <stdexcept>
# include <iterator>
# include <exception>

# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"


template <typename T>
typename T::iterator easyfind(T& container, int value)
{
		typename T::iterator it = std::find(container.begin(), container.end(), value);
		if (it == container.end())
			throw std::runtime_error("Value not found");
		return it;
}

#endif