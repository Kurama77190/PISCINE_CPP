/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:34:59 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/28 22:32:29 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <stdexcept>
#include <iterator>

/*
  Checks if the file is empty.
  Throws an exception if the file cannot be opened or is empty.
 */
bool utils::isEmptyFile(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file: " + filename);
	}
	if (file.peek() == std::ifstream::traits_type::eof()) {
		file.close();
		throw std::runtime_error("File is empty: " + filename);
	}
	return false;
}

/*
  Checks if the file has a .txt postfix.
  Throws an exception if the file does not have the expected format.
  Returns true if the file has a valid .txt postfix.
 */
bool utils::postfix(const std::string &str) {
	std::string::const_iterator it = str.end() - 4;
	if (str.size() < 4 || *it != '.' || *(it - 1) != 't' || *(it - 2) != 'x' || *(it - 3) != 't')
		throw std::runtime_error("Invalid file format. Expected .txt file.");
	return true;
}

// utils::isValidDate(const std::string &date) {
// 	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
// 		return false;
// 	for (size_t i = 0; i < date.size(); ++i) {
// 		if (i == 4 || i == 7)
// 			continue;
// 		if (!isdigit(date[i]))
// 			return false;
// 	}
// 	return true;
// }

// utils::isValidValue(const std::string &value) {
// 	if (value.empty() || value[0] == '-' || value[0] == '+')
// 		return false;
// 	for (size_t i = 0; i < value.size(); ++i) {
// 		if (!isdigit(value[i]) && value[i] != '.')
// 			return false;
// 	}
// 	return true;
// }

// utils::parseValue(const std::string &value) {
// 	try {
// 		return std::stod(value);
// 	} catch (const std::invalid_argument &) {
// 		return 0.0; // or throw an exception
// 	}
// }

// utils::trim(const std::string &str) {
// 	size_t start = str.find_first_not_of(" \t\n\r");
// 	size_t end = str.find_last_not_of(" \t\n\r");
// 	if (start == std::string::npos || end == std::string::npos)
// 		return "";
// 	return str.substr(start, end - start + 1);
// }

// utils::formatDate(const std::string &date) {
// 	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
// 		return date; // Invalid format, return as is
// 	return date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);
// }
