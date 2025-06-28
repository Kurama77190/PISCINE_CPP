/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:05:00 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/28 22:29:05 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.hpp"

BitcoinExchange::BitcoinExchange() {
	// Constructor implementation
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {
	// Copy constructor implementation
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	// Destructor implementation
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
	std::ifstream data("data.csv");
	if (!data.is_open() || utils::isEmptyFile("data.csv")) {
		throw std::runtime_error("Could not open data.csv file.");
	}


	if (!utils::postfix(filename)) {
		throw std::runtime_error("Invalid file format. Expected .txt file.");
	}
	std::ifstream file(filename.c_str());
	if (!file.is_open() || utils::postfix(filename)) {
		throw std::runtime_error(std::string("Could not open : ") + filename);
	}
	
	std::cout << "Loading data from " << filename << "..." << std::endl;
// 	std::string line;
// 	while (std::getline(file, line)) {
// 		std::istringstream iss(line);
// 		std::string date;
// 		double value;
// 		if (iss >> date >> value) {
// 			_data[date] = value;
// 		}
// 	}
	data.close();
	file.close();
}

// double BitcoinExchange::getValue(const std::string &date) const {
// 	auto it = _data.find(date);
// 	if (it != _data.end()) {
// 		return it->second;
// 	} else {
// 		throw std::out_of_range("Date not found in database.");
// 	}
// }

// void BitcoinExchange::printData() const {
// 	for (const auto &pair : _data) {
// 		std::cout << pair.first << ": " << pair.second << std::endl;
// 	}
// }

// // End of BitcoinExchange.cpp