/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 00:13:26 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/21 19:41:09 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter &src) {};
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) { return *this; };

void ScalarConverter::convert(const std::string &literal)
{
	try {
		if (isChar(literal))
			return display(literal[0]);

		else if (isInt(literal)) {
			long l = std::strtol(literal.c_str(), NULL, 10);
			if (l < MIN_INT || l > MAX_INT)
				throw std::out_of_range("int overflow");
			return display(static_cast<int>(l));
		}
		if (isFloat(literal)) {
			double d = std::strtod(literal.c_str(), NULL);
			if (d < -MAX_FLOAT || d > MAX_FLOAT)
				throw std::out_of_range("float overflow");
			return display(static_cast<float>(d), isSpecial(literal));
		}

		if (isDouble(literal)) {
			char* end;
			double d = std::strtod(literal.c_str(), &end);
			if (d == HUGE_VAL || d == -HUGE_VAL)
				throw std::out_of_range("double overflow");
			return display(d, isSpecial(literal));
		}

		std::cerr << "Invalid literal" << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Convert error: " << e.what() << std::endl;
	}
}

// void ScalarConverter::convert(const std::string &literal)
// {
// 	try {
// 	if (isChar(literal))
// 		display(literal[0]);
// 	else if (isInt(literal))
// 		display(std::stoi(literal));
// 	else if (isFloat(literal))
// 		display(std::stof(literal), isSpecial(literal));
// 	else if (isDouble(literal), isSpecial(literal))
// 		display(std::stod(literal), isSpecial(literal));
// 	else
// 		std::cerr << "Invalid literal" << std::endl;
// 	} catch (const std::exception &e) {
// 		std::cerr << "Convert error: " << e.what() << std::endl;
// 	}
// }
