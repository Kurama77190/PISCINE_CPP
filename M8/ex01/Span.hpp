/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:35:45 by sben-tay          #+#    #+#             */
/*   Updated: 2025/05/06 18:46:51 by sben-tay         ###   ########.fr       */
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
# include <ctime>
# include <cstdlib>

# define BLUE "\033[34m"
# define RED "\033[31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"



class Span {
public:
	Span(unsigned int N); //canonical
	Span(const Span &src); //canonical
	~Span(); //canonical
	Span&			operator=(const Span &rhs); //canonical

	void			addNumber(int);
	int				shortestSpan();
	int				longestSpan();

	void			addMaxCapacity();
	void			displaySpan();

	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);


 private:

	unsigned int		_maxSize;
	std::vector<int>	_span;
};


#endif