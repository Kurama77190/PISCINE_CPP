/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 00:13:26 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/19 04:51:16 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter &src) {};
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  return *this;
};

void ScalarConverter::convert(const std::string &literal)
{
	if (isChar(literal))
		display(literal[0]);
	else if (isInt(literal))
		display(std::stoi(literal));
	else if (isDouble(literal), isSpecial(literal))
		display(std::stod(literal), isSpecial(literal));
	else if (isFloat(literal))
		display(std::stof(literal), isSpecial(literal));
	else
		std::cerr << "Invalid literal" << std::endl;
}
