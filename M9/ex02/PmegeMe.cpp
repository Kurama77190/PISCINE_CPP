/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmegeMe.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:15:23 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/10 18:23:49 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {}

PmergeMe::~PmergeMe( void ) {}

PmergeMe::PmergeMe( const PmergeMe &other ) {
	PmergeMe::operator=(other);
}

PmergeMe& PmergeMe::operator=( const PmergeMe &other ) {
	return *this;
}

void PmergeMe::sortVector( std::vector<int>& vec ) {
	if (vec.empty()) {
		throw std::invalid_argument("Vector is empty");
	}
	
	size_t left = 0;
	size_t right = vec.size() - 1;
	mergeSortVector(vec, left, right);
}

void PmergeMe::sortDeque( std::deque<int>& deq ) {
	if (deq.empty()) {
		throw std::invalid_argument("Deque is empty");
	}
	size_t left = 0;
	size_t right = deq.size() - 1;
	mergeSortDeque(deq, left, right);
}



