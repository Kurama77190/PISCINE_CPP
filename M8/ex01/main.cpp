/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 04:17:09 by sben-tay          #+#    #+#             */
/*   Updated: 2025/05/06 18:49:15 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"



int main()
{
	try{

	std::cout << BLUE << "----- TEST SPAN EXCEPTION -----" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// sp.addNumber(0); // uncomment this line to see exception
	sp.displaySpan();
	} catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}

	try{
	std::cout << BLUE << "----- TEST SHORTESTSPAN & LONGESTSPAN -----" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	} catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}
	
	try{
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
	std::cout << BLUE << "----- TEST ADDMAXCAPACITY -----" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;
	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << RED << " - Before addMaxCapacity: " << RESET << std::endl;
	sp.displaySpan();
	sp.addMaxCapacity();
	std::cout << RED << "After addMaxCapacity: " <<RESET << std::endl;
	sp.displaySpan();
	} catch(std::exception & e){
		std::cout << e.what() << std::endl;
	}

}
