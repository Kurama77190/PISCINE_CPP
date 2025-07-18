/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:22:54 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/18 19:45:30 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
		return 1;
	}
	
	try {
		
		for (int i = 1; i < argc; ++i)
			PmergeMe::validateInput(argv[i]);
		
		std::vector<int> inputVec;
		for (int i = 1; i < argc; ++i) {
			inputVec.push_back(std::atoi(argv[i]));
		}
		std::deque<int> inputDeq;
		for (int i = 1; i < argc; ++i) {
			inputDeq.push_back(std::atoi(argv[i]));
		}
		
		PmergeMe data;
		PmergeMe data2;
		
		data.sortVector(inputVec);
		data2.sortDeque(inputDeq);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

