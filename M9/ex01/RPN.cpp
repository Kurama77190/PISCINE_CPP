/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:22:47 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/04 19:51:53 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( std::string input ) {
	
}

RPN::~RPN( void ) {}

RPN::RPN( const RPN &other ) {}

RPN &RPN::operator=( const RPN &other ) {}

void RPN::evaluate(std::string const &input) {
	std::istringstream iss(input);
	std::string token;
	
	while ( iss >> token) {
		char *check;

		if (std::isdigit(token[0]) && token.size() == 1) {
			_stack.push(std::strtol(token.c_str(), &check, 10));
			if (*check) {
				throw std::invalid_argument("Invalid number: " + token);
			}
		}
		else if (std::string("+-*/").find(token[0]) != std::string::npos && token.length() == 1) {
			if ()
		}
		
		
			
	}
}
