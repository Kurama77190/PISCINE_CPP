/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:03:58 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/18 19:10:13 by sben-tay         ###   ########.fr       */
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
# include <cctype>


class PmergeMe {

	public:

		PmergeMe( const std::vector<int>& input );
		PmergeMe( const std::deque<int>& input );
		~PmergeMe( void );
		PmergeMe( const PmergeMe &other );
		PmergeMe &operator=( const PmergeMe &other );
		
		void sortVector( std::vector<int>& vec );
		void sortDeque( std::deque<int>& deq );

	private:
		std::vector<int> _vecTmp;
		std::deque<int> _deqTmp;
	
		std::vector<std::pair<int, int> > createSortedPairsVec(std::vector<int>& vec, int& straggler);
		std::deque<std::pair<int, int> > createSortedPairsDeq(std::deque<int>& deq, int& straggler);
		
		std::vector<int> buildAndSortMainChainVec(const std::vector<std::pair<int, int> >& pairs);
		std::deque<int> buildAndSortMainChainDeq(const std::deque<std::pair<int, int> >& pairs);
		
		void insertPendingElements(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain); //  la suite Jacobsthal
		void insertPendingElements(const std::deque<std::pair<int, int> >& pairs, std::deque<int>& mainChain); // ...
		
		std::vector<int> recursiveSortVector(std::vector<int>& vec);
		std::deque<int> recursiveSortDeque(std::deque<int>& vec);

		void insertStraggler(int straggler, std::vector<int>& mainChain);
		void insertStraggler(int straggler, std::deque<int>& mainChain);

		//void validateInput( const std::string& input );
		//std::vector<int> parseInput( const std::string& input );
		
		void displayResult( const std::vector<int>& result );
		void displayResult( const std::deque<int>& result );
};

template <typename Container>
bool isSorted(const Container& container) {
	if (container.empty())
		return true;

	typename Container::const_iterator it = container.begin();
	typename Container::const_iterator next = it;
	++next;

	while (next != container.end()) {
		if (*next < *it)
			return false;
		++it;
		++next;
	}
	return true;
}


#endif