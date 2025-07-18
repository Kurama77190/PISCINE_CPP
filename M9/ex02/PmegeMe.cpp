/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmegeMe.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:15:23 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/18 19:11:30 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( const std::vector<int>& input ) {
	if (input.empty()) {
		throw std::invalid_argument("Input vector is empty");
	}
	_vecTmp = input;
	sortVector(_vecTmp);
}

PmergeMe::PmergeMe( const std::deque<int>& input ) {
	if (input.empty()) {
		throw std::invalid_argument("Input deque is empty");
	}
	
	_deqTmp = input;
	sortDeque(_deqTmp);
}

PmergeMe::~PmergeMe( void ) {  }

PmergeMe::PmergeMe( const PmergeMe &other ) {
	PmergeMe::operator=(other);
}

PmergeMe& PmergeMe::operator=( const PmergeMe &other ) {
	(void)other;
	return *this;
}

void PmergeMe::sortVector( std::vector<int>& vec ) {
	if (vec.empty()) {
		throw std::invalid_argument("Vector is empty");
	}
	int straggler;
	//etape 1
	std::vector<std::pair<int , int> > pair = createSortedPairsVec(vec, straggler);
	//etape 2
	std::vector<int> mainChain = buildAndSortMainChainVec(pair);
	//etape 3
	insertPendingElements(pair, mainChain);
	//etape 4bis
	if (straggler != -1) {
		insertStraggler(straggler, mainChain);
	}
	_vecTmp = mainChain; // Mettre à jour le vecteur temporaire avec le résultat trié
	//displayResult(_vecTmp); // Afficher le résultat trié
	if (isSorted(_vecTmp))
		std::cout << "Vector is sorted.✅ " << std::endl;
	else
		std::cout << "Vector is not sorted.⛔" << std::endl;
}

void PmergeMe::sortDeque( std::deque<int>& deq ) {
	if (deq.empty()) {
		throw std::invalid_argument("Deque is empty");
	}
	int straggler;
	//etape 1
	std::deque<std::pair<int , int> > pair = createSortedPairsDeq(deq, straggler);
	//etape 2
	std::deque<int> mainChain = buildAndSortMainChainDeq(pair);
	//etape 3
	insertPendingElements(pair, mainChain);
	//etape 4bis
	if (straggler != -1) {
		insertStraggler(straggler, mainChain);
	}
	_deqTmp = mainChain; // Mettre à jour la deque temporaire avec le résultat trié	
	//displayResult(_deqTmp); // Afficher le résultat trié
	if (isSorted(_deqTmp))
		std::cout << "Deque is sorted.✅ " << std::endl;
	else
		std::cout << "Deque is not sorted.⛔" << std::endl;
}

std::vector<std::pair<int, int> > PmergeMe::createSortedPairsVec(std::vector<int>& vec, int& straggler) {
	std::vector<std::pair<int, int> > pairs;
	straggler = -1;

	// Si taille impaire, on garde le dernier de côté
	if (vec.size() % 2 != 0) {
		straggler = vec.back();
		vec.pop_back();
	}

	for (size_t i = 0; i < vec.size(); i += 2) {
		int a = vec[i];
		int b = vec[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	return pairs;
}

std::deque<std::pair<int, int> > PmergeMe::createSortedPairsDeq(std::deque<int>& deq, int& straggler) {
	std::deque<std::pair<int, int> > pairs;
	straggler = -1;

	if (deq.size() % 2 != 0) {
		straggler = deq.back();
		deq.pop_back();
	}

	for (size_t i = 0; i < deq.size(); i += 2) {
		int a = deq[i];
		int b = deq[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	return pairs;
}

std::vector<int> PmergeMe::buildAndSortMainChainVec(const std::vector<std::pair<int, int> >& pairs) {
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i) {
	mainChain.push_back(pairs[i].second); // second = le plus grand de la paire
	}

	// 🔁 Appel récursif pour trier la mainChain (true ford Jonhson)
	if (mainChain.size() <= 1)
		return mainChain;
	return recursiveSortVector(mainChain);
}

std::deque<int> PmergeMe::buildAndSortMainChainDeq(const std::deque<std::pair<int, int> >& pairs) {
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i) {
	mainChain.push_back(pairs[i].second); // second = le plus grand de la paire
	}

	// 🔁 Appel récursif pour trier la mainChain (true ford Jonhson)
	if (mainChain.size() <= 1)
		return mainChain;
	return recursiveSortDeque(mainChain);
}

std::vector<int> PmergeMe::recursiveSortVector(std::vector<int>& vec) {
	if (vec.size() <= 1)
		return vec;

	int straggler;
	std::vector<std::pair<int, int> > pairs = createSortedPairsVec(vec, straggler);
	std::vector<int> mainChain = buildAndSortMainChainVec(pairs);
	insertPendingElements(pairs, mainChain);
	if (straggler != -1)
		insertStraggler(straggler, mainChain);
	return mainChain;
}

std::deque<int> PmergeMe::recursiveSortDeque(std::deque<int>& vec) {
	if (vec.size() <= 1)
		return vec;

	int straggler;
	std::deque<std::pair<int, int> > pairs = createSortedPairsDeq(vec, straggler);
	std::deque<int> mainChain = buildAndSortMainChainDeq(pairs);
	insertPendingElements(pairs, mainChain);
	if (straggler != -1)
		insertStraggler(straggler, mainChain);
	return mainChain;
}

void PmergeMe::insertPendingElements(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		int toInsert = pairs[i].first;

		// Insertion par recherche de la bonne position (tri par insertion)
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), toInsert);
		mainChain.insert(pos, toInsert);
	}
}

void PmergeMe::insertPendingElements(const std::deque<std::pair<int, int> >& pairs, std::deque<int>& mainChain) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		int toInsert = pairs[i].first;

		// Insertion par recherche de la bonne position (tri par insertion)
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), toInsert);
		mainChain.insert(pos, toInsert);
	}
}

void PmergeMe::insertStraggler(int straggler, std::vector<int>& mainChain) {
	std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
	mainChain.insert(pos, straggler);
}

void PmergeMe::insertStraggler(int straggler, std::deque<int>& mainChain) {
	std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
	mainChain.insert(pos, straggler);
}

void PmergeMe::displayResult( const std::vector<int>& result ) {
std::vector<int>::const_iterator it = result.begin();
	std::cout << "Sorted Vector: ";
	for (; it != result.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;	
}

void PmergeMe::displayResult( const std::deque<int>& result ) {
	std::deque<int>::const_iterator it = result.begin();
	std::cout << "Sorted Deque: ";
	for (; it != result.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
