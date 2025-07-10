/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:03:58 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/10 18:19:43 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <stdexcept>
# include <iterator>
# include <sstream>
# include <string>
# include <limits>
# include <cstdlib>




class PmergeMe {
public:
	PmergeMe( void );
	~PmergeMe( void );
	PmergeMe( const PmergeMe &other );
	PmergeMe &operator=( const PmergeMe &other );
	
	void sortVector( std::vector<int>& vec );
    void sortDeque( std::deque<int>& deq );

private:
	void mergeSortVector( std::vector<int>& vec, size_t left, size_t right );
	void mergeVector( std::vector<int>& vec, size_t left, size_t mid, size_t right );
	
	void mergeSortDeque( std::deque<int>& deq, size_t left, size_t right );
	void mergeDeque( std::deque<int>& deq, size_t left, size_t mid, size_t right );

	void validateInput( const std::string& input );
	std::vector<int> parseInput( const std::string& input );
};


#endif