/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:18:55 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/30 18:25:54 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <string>
#include <iterator>
#include <fstream>
#include <iostream>
#include <cstdlib>

namespace utils {
		
	/*
	* Checks if the given string has a ".txt" suffix.
	*
	* str: The string to check.
	*
	* returns: true if the string ends with ".txt", otherwise throws an exception.
	*/
	bool postFix(const std::string &str) {
		if (str.substr(str.size() - 4) != ".txt")
			throw std::runtime_error("Invalid file extension: " + str);
		return true;
	}

	bool emptyFile(const std::string &filename) {
		std::ifstream file;

		file.open(filename.c_str());
		if (!file.is_open())
			throw std::runtime_error("Error opening file: " + filename);
		if (file.peek() == std::ifstream::traits_type::eof()) {
			file.close();
			throw std::runtime_error("File is empty: " + filename);
		}
		file.close();
		return false;
	}


	bool invalidDate(const std::string &date) {
		if (date.size() != 10 || date[4] != '-' || date[7] != '-')
			return true;
		
		for (size_t i = 0; i < date.size(); ++i) {
			if ((i == 4 || i == 7) && date[i] != '-') {
				return true;
			} else if (i != 4 && i != 7 && !isdigit(date[i])) {
				return true;
			}
		}
		return false;
	}

	std::map<std::string, double> splitDataOnMap(const std::string &line, char separator) {
		std::map<std::string, double> dataMap;
		std::size_t pos = line.find(separator);
		
		if (pos == std::string::npos)
			throw std::invalid_argument("Error: Invalid line format in database.");
		
		std::string key = line.substr(0, pos);
		if (invalidDate(key) || key.empty() || invalidDate(key) || key.size() != 10)
			throw std::invalid_argument("Error: Invalid date format in database: " + key);
		std::string value = line.substr(pos + 1);
		if (value < "0" || value > "1000" || value.size() > 4 || value.empty())
			throw std::invalid_argument("Error: Invalid value in database: " + value);
		
		
		double fvalue = std::atoi(value.c_str());
		if (fvalue < 0)
			throw std::invalid_argument("Error: Negative value in database.");
		
		dataMap[key] = fvalue;
		return dataMap;
	}

	

}
