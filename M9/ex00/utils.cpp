/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:18:55 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/30 16:43:07 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <string>
#include <iterator>
#include <fstream>
#include <iostream>

/*
 * Checks if the given string has a ".txt" suffix.
 *
 * str: The string to check.
 *
 * returns: true if the string ends with ".txt", otherwise throws an exception.
 */
bool utils::postFix(const std::string &str) {
	if (str.substr(str.size() - 4) != ".txt")
		throw std::runtime_error("Invalid file extension: " + str);
	return true;
}

bool utils::emptyFile(const std::string &filename) {
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

// bool isValidDate(const std::string &date) {
// 	// Check if the date is in the format YYYY-MM-DD
// 	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
// 		return false;
// 	}
// 	// Check if the year, month, and day are all digits
// 	for (char c : date) {
// 		if (!std::isdigit(c) && c != '-') {
// 			return false;
// 		}
// 	}
// 	return true;
// }

