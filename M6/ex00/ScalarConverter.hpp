/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 04:21:02 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/20 11:23:10 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <cctype>
# include <iomanip>

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()

#define MIN_CHAR 0
#define MAX_CHAR 127

class ScalarConverter {
public:
	static void convert(const std::string &literal);
	
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &rhs);
};

void display(char c);
void display(int i);
void display(float f, bool isSpecial);
void display(double d, bool isSpecial);

bool isChar(const std::string &literal);
bool isInt(const std::string &literal);
bool isFloat(const std::string &literal);
bool isDouble(const std::string &literal);
bool isSpecial(const std::string &literal);


#endif
 