/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:16:29 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/23 13:35:23 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isChar(const std::string &literal)
{
	return (literal.length() == 1 && isprint(literal[0])) && isalpha(literal[0]);
}

bool isInt(const std::string &literal)
{
	for (size_t i = 0; i < literal.length(); ++i)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

bool isFloat(const std::string &literal)
{
	if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
		return false;

	std::string core = literal.substr(0, literal.length() - 1);
	bool hasDecimal = false;

	for (size_t i = 0; i < core.length(); ++i)
	{
		if (i == 0 && (core[i] == '+' || core[i] == '-'))
			continue;
		if (core[i] == '.')
		{
			if (hasDecimal)
				return false;
			hasDecimal = true;
		}
		else if (!isdigit(core[i]))
			return false;
	}

	return hasDecimal;
}

bool isDouble(const std::string &literal)
{
	if (literal.find('.') == std::string::npos)
		return false;
	for (size_t i = 0; i < literal.length(); ++i)
	{
		if (literal[i] == '+' || literal[i] == '-')
			i++;
		else if (!isdigit(literal[i]) && literal[i] != '.')
			return false;
	}
	return true;
}

bool isSpecial(const std::string &literal)
{
	return (literal == "nan" || literal == "inf" || literal == "-inff"
			|| literal == "+inff" || literal == "nanf" || literal == "inff"
			|| literal == "-inf" || literal == "+inf");
}

