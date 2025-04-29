/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:38:31 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/29 20:56:55 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	test_vector();
void	test_list();
void test_deque();

int main() {
	std::cout << BLUE << "TESTING EASYFIND WITH DIFFERENT CONTAINERS:" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------------------" <<  RESET << std::endl;
	
	test_vector();
	test_list();
	test_deque();
	
}


void	test_vector() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	
	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << GREEN << "Found: " << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	test_list() {
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	// lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	
	try {
		std::list<int>::iterator it = easyfind(lst, 3);
		std::cout << GREEN << "Found: " << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void test_deque() {
	std::deque<int> deq;
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(3);
	deq.push_back(4);
	deq.push_back(5);

	try {
		std::deque<int>::iterator it = easyfind(deq, 3);
		std::cout << GREEN << "Found: " << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
