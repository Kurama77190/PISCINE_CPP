/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:22:47 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/04 23:14:26 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {}

RPN::~RPN( void ) {}

RPN::RPN( const RPN &other ) {
	_stack = other._stack;
}

RPN &RPN::operator=( const RPN &other ) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

void RPN::evaluate(std::string const &input) {
	std::istringstream iss(input);
	std::string token;
	
	while ( iss >> token) {
		char *check;

		if (std::isdigit(token[0]) && token.size() == 1) {
			_stack.push(std::strtol(token.c_str(), &check, 10));
			if (*check) {
				throw std::invalid_argument("Error: not enough operands: " + token);
			}
		}
		else if (_stack.size() > 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
			int a = _stack.top(); _stack.pop();
			int b = _stack.top(); _stack.pop();
			int result = applyOperation(b, a, token[0]);
			_stack.push(result);
		}
	}
	if (_stack.size() != 1) {
		throw std::runtime_error("Error");
	}
}

int RPN::applyOperation(int a, int b, char op) {
	if (op == '+') {
		return a + b;
	} else if (op == '-') {
		return a - b;
	} else if (op == '*') {
		return a * b;
	} else if (op == '/') {
		if (b == 0) {
			throw std::runtime_error("Error: division by zero");
		}
		return a / b;
	} else {
		throw std::invalid_argument("Error: unknown operator: " + std::string(1, op));
	}
}

void RPN::displayStack() const {
	std::stack<int> temp = _stack;
	while (!temp.empty()) {
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;
}
