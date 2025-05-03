/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:35:45 by sben-tay          #+#    #+#             */
/*   Updated: 2025/05/03 05:13:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <climits>
# include <cstdlib>
# include <ctime>
# include <iterator>
# include <stdexcept>
# include <cmath>


class Span {
public:
	Span(unsigned int N); //canonical
	Span(const Span &src); //canonical
	~Span(); //canonical
	Span&			operator=(const Span &rhs); //canonical

	void			addNumber(int);
	int				shortestSpan();
	int				longestSpan();

	void			addMaxCapacity(std::vector<int>::iterator begin, std::vector<int>::iterator end);

 private:

	unsigned int		_maxSize;
	std::vector<int>	_span;
};


#endif