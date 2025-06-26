/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 04:17:09 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/26 17:48:08 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"



int main()
{
	try {

	std::cout << BLUE << "----- TEST SPAN EXCEPTION -----" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// sp.addNumber(0); // uncomment this line to see exception
	sp.displaySpan();
	
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
	std::cout << BLUE << "----- TEST SHORTESTSPAN & LONGESTSPAN -----" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	

	try {
	std::cout << BLUE << "----- TEST RANGE OF ITERATORS -----" << RESET << std::endl;
	Span sp = Span(5);
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	
	std::cout << RED << " Before adding numbers from vector: " << RESET << std::endl;
	sp.displaySpan();

	sp.addNumbers(vec.begin(), vec.end());
	
	std::cout << RED << " After adding numbers from vector: " << RESET << std::endl;
	sp.displaySpan();

	std::cout << "Exception from addNumbers" << std::endl;
	std::vector<int> vec2;
	vec2.push_back(6);
	vec2.push_back(7);
	vec2.push_back(8);
	vec2.push_back(9);
	vec2.push_back(10);
	vec2.push_back(11);
	
	sp.addNumbers(vec2.begin(), vec2.end());

	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
