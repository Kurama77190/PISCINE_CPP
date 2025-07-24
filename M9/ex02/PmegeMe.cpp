/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmegeMe.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:15:23 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/24 14:32:18 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

PmergeMe::PmergeMe(const std::vector<unsigned int>& vec, const std::deque<unsigned int>& deq)
	: _time(0), _start(0), _end(0), _vec(vec), _deq(deq)  {
	process();
}

// ----------------------------- FONCTION PRINCIPALE ------------------------ //

void PmergeMe::process() {
	std::cout << "Before: ";
	display(_vec);
	std::cout << std::endl;

	_start = clock();
	sort(_vec);
	_end = clock();
	_time = static_cast<double>(_end - _start) / CLOCKS_PER_SEC * 1e6;
	std::cout << "After: ";
	display(_vec);
	std::cout << (isSorted(_vec) ? "✅ " : "⛔") << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << _time << " us" << std::endl;

	_start = clock();
	sort(_deq);
	_end = clock();
	_time = static_cast<double>(_end - _start) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << _time << " us" << std::endl;
}

// ------------------------------- VECTOR ----------------------------------- //

void PmergeMe::sort(std::vector<unsigned int>& arr) {
	if (arr.size() < 2)
		return;

	// -------------------------------------
	// Step 0 : Détection du straggler (optionnel)
	// -------------------------------------
	
	unsigned int stragglerExists = arr.size() % 2;
	unsigned int straggler = 0;
	unsigned int end = arr.size();

	if (stragglerExists) {
		straggler = arr.back();
		arr.pop_back();
		end--;
	}

	// -------------------------------------
	// Step 1 : Création des paires (min, max)
	// -------------------------------------
	
	std::deque<std::pair<unsigned int, unsigned int> > pairs;
	for (unsigned int i = 0; i < end; i += 2) {
		unsigned int a = arr[i];
		unsigned int b = arr[i + 1];
		pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}
	
	// -------------------------------------
	// Step 2 : Extraction des "max" → mainChain
	// -------------------------------------
	
	std::vector<unsigned int> mainChain;
	for (unsigned int i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].second);

	// -------------------------------------
	// Step 3 : Tri récursif de la mainChain
	// (ne modifie pas les paires originales)
	// -------------------------------------
	
	sort(mainChain);

	// -------------------------------------
	// Step 4 : Ajouter le straggler dans pend si présent (optionnel)
	// -------------------------------------
	
	std::vector<unsigned int> pend;
	for (unsigned int i = 0; i < pairs.size(); ++i)
		pend.push_back(pairs[i].first);
	if (stragglerExists)
		pend.push_back(straggler);

	// -------------------------------------
	// Step 5 : Génération des indices Jacobsthal
	// -------------------------------------
	
	std::vector<unsigned int> jacobIndexes = getJacobsthalIndexes(pend.size());

	// -------------------------------------
	// Step 6 : Insertion des pend dans la mainChain
	// -------------------------------------
	
	for (size_t i = 0; i < jacobIndexes.size(); ++i) {
		unsigned int idx = jacobIndexes[i];
		if (idx >= pend.size()) continue;

		std::vector<unsigned int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pend[idx]);
		mainChain.insert(pos, pend[idx]);
	}

	// -------------------------------------
	// Step 7 : Mise à jour du tableau d'origine
	// -------------------------------------
	
	arr = mainChain;
}


// ------------------------------- DEQUE ------------------------------------ //

void PmergeMe::sort(std::deque<unsigned int>& arr) {
	if (arr.size() < 2)
		return;

	// -------------------------------------
	// Step 0 : Détection du straggler
	// -------------------------------------
	
	unsigned int stragglerExists = arr.size() % 2;
	unsigned int straggler = 0;
	unsigned int end = arr.size();

	if (stragglerExists) {
		straggler = arr.back();
		arr.pop_back();
		end--;
	}

	// -------------------------------------
	// Step 1 : Création des paires (min, max)
	// -------------------------------------
	
	std::deque<std::pair<unsigned int, unsigned int> > pairs;
	for (unsigned int i = 0; i < end; i += 2) {
		unsigned int a = arr[i];
		unsigned int b = arr[i + 1];
		pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	// -------------------------------------
	// Step 2 : Extraction des "max" → mainChain
	// -------------------------------------
	
	std::deque<unsigned int> mainChain;
	for (unsigned int i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].second);

	// -------------------------------------
	// Step 3 : Tri récursif de la mainChain
	// (ne modifie pas les paires originales)
	// -------------------------------------
	
	sort(mainChain);

	// -------------------------------------
	// Step 4 : Ajouter le straggler dans pend si présent
	// -------------------------------------
	
	std::deque<unsigned int> pend;
	for (unsigned int i = 0; i < pairs.size(); ++i)
		pend.push_back(pairs[i].first);
	if (stragglerExists)
		pend.push_back(straggler);

	// -------------------------------------
	// Step 5 : Génération des indices Jacobsthal
	// -------------------------------------
	
	std::vector<unsigned int> jacobIndexes = getJacobsthalIndexes(pend.size());

	// -------------------------------------
	// Step 6 : Insertion des pend dans la mainChain
	// -------------------------------------
	
	for (size_t i = 0; i < jacobIndexes.size(); ++i) {
		unsigned int idx = jacobIndexes[i];

		std::deque<unsigned int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pend[idx]);
		mainChain.insert(pos, pend[idx]);
	}

	// -------------------------------------
	// Step 7 : Mise à jour du tableau d'origine
	// -------------------------------------
	
	arr = mainChain;
}


// ------------------------------- TOOLS ------------------------------------ //

template <typename Container>
bool isSorted(const Container& cont) {
	for (size_t i = 1; i < cont.size(); ++i) {
		if (cont[i - 1] > cont[i])
			return false;
	}
	return true;
}

template <typename Container>
void display(const Container& cont) {
	for (typename Container::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << " ";
}

std::vector<unsigned int> getJacobsthalIndexes(unsigned int size) {
	std::vector<unsigned int> index;
	std::vector<bool> seen(size, false);
	unsigned int i = 0;
	unsigned int j = 1;
	while (j < size) {
		if (!seen[j]) {
			index.push_back(j);
			seen[j] = true;
		}
		unsigned int next = j + 2 * i;
		i = j;
		j = next;
	}
	for (unsigned int k = 0; k < size; ++k) {
		if (!seen[k])
			index.push_back(k);
	}
	return index;
}

void parseInput(int argc, char **argv) {
	if (argc == 2) {
	}
	if (argc > 2) {
		for (int i = 1; argv[i]; i++) {
			std::string arg = std::string(argv[i]);
			for (int j = 0; argv[i][j]; j++) {
				if (arg.empty() || !std::isdigit(argv[i][j]))
					throw std::invalid_argument("Invalid arguments");
			}
			double tmp;
			char *check;
			if (arg.size() > 10 || (tmp = std::strtod(arg.c_str(), &check)) > 2147483647)
				throw std::out_of_range("Overflow detected");
			if (*check)
				throw std::invalid_argument("Invalid argument: " + arg);
		}
	}
}
