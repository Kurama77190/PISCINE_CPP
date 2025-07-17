/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:18:55 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/17 18:45:08 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <string>
#include <iterator>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

#define RED "\033[31m"
#define RESET "\033[0m"
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


	static bool isLeapYear(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	bool invalidDate(const std::string &content) {

		std::string date = utils::trim(content.substr(0, content.find('|')));
		if (date.empty()) {
			return true;
		}
		if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
			std::cerr << RED << "Error: bad input => " << content <<  RESET << std::endl;
			return true;
		}

		int year = std::atoi(date.substr(0, 4).c_str());
		int month = std::atoi(date.substr(5, 2).c_str());
		int day = std::atoi(date.substr(8, 2).c_str());

		if (year < 2009 || year > 2025) {
			std::cerr << RED << "Error: bad input => " << content <<  RESET << std::endl;
			return true;
		}
		if (month < 1 || month > 12) {
			std::cerr << RED << "Error: bad input => " << content <<  RESET << std::endl;
			return true;
		}

		int maxDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && isLeapYear(year))
			maxDays[1] = 29;

		if (day < 1 || day > maxDays[month - 1]) {
			std::cerr << RED << "Error: bad input => " << content <<  RESET << std::endl;
			return true;
		}
		return false;
	}


	bool invalidValue(const std::string &content) {
		std::string valueStr = utils::trim(content.substr(content.find('|') + 1, content.size()));
		if (valueStr.empty()) {
			std::cerr << RED << "Error: bad input: " << content << RESET << std::endl;
			return true;
		}
		char *check;
		double value = strtod(valueStr.c_str(), &check);
		if (*check) {
			std::cerr << RED << "Error: bad input: " << content << RESET << std::endl;
			return true;
		}
		if (value < 0) {
			std::cerr << RED << std::fixed << std::setprecision(2) << "Error: not a positive number => " << content << RESET << std::endl;
			return true;
		}
		if (value > 1000) {
			std::cerr << RED << "Error: too large a number => " << content << RESET << std::endl;
			return true;
		}
		return false;
	}

	void splitDataOnMap(std::ifstream &line, std::map<std::string, double> &dataMap) {
		std::string content;
		bool dejaVu = false;

		while(std::getline(line, content)) {
			if (content.empty())
				continue; // Skip empty lines or header line
			if (content.compare("date,exchange_rate") == 0 && dejaVu == false) {
				dejaVu = true;
				continue;
			}
			else if (content.compare("date,exchange_rate") == 0 && dejaVu == true)
				throw std::invalid_argument("Error: Invalid header line in database.");
			std::size_t pos = content.find(",");
	
			if (pos == std::string::npos)
				throw std::invalid_argument("Error: Invalid line format in database.");
			
			std::string key = utils::trim(content.substr(0, pos));
			if (key.empty() || key.size() != 10 || utils::invalidDate(key))
				throw std::invalid_argument("Error: Invalid date format in database: " + key);
			std::string value = utils::trim(content.substr(pos + 1));
			if (value.empty())
				throw std::invalid_argument("Error: Invalid value in database: " + value);
			
			char *check;
			double fvalue = std::strtod(value.c_str(), &check);
			if (*check)
				throw std::invalid_argument("Error: Invalid value in database: " + value);
			dataMap[key] = fvalue;
		}
	}
	
	std::string trim(std::string str) {
		size_t first = str.find_first_not_of(" \t\n\r\f\v");
		size_t last = str.find_last_not_of(" \t\n\r\f\v");
		if (first == std::string::npos || last == std::string::npos)
			return ""; // String is empty or contains only whitespace
		return str.substr(first, last - first + 1);
	}

}

