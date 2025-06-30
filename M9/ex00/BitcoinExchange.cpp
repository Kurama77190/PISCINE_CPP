/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:05:00 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/30 16:51:48 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {}

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs) {}

void BitcoinExchange::loadDatabase(std::string filename) {
	//open database data.csv
	std::ifstream dataCsv("data.csv");
	if (!dataCsv.is_open() || utils::emptyFile("data.csv")) {
		throw std::ios_base::failure(std::string("Error: Could not open file: ") + filename);
	}

	//open database file.txt
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open() || utils::emptyFile(filename) || !utils::postFix(filename)) {
		dataCsv.close();
		throw std::ios_base::failure(std::string("Error: Could not open file: ") + filename);
	}

	// Read the first line of file.txt to skip the header
	std::string line;
	while (std::getline(inputFile, line)) {
			processLine(line);
	}
	
	dataCsv.close();
	inputFile.close();
}

// void BitcoinExchange::processLine(const std::string &line) {
// 	std::string key;
// 	std::string value;
// 	std::size_t pos = line.find(separator);

// 	if (pos == std::string::npos)
// 		throw std::invalid_argument("Error: Invalid line format in database.");

// 	key = line.substr(0, pos);
// 	value = line.substr(pos + 1);

// 	// Conversion en double
// 	double fvalue = std::atof(value.c_str());
// 	if (fvalue < 0) {
// 		throw std::invalid_argument("Error: Negative value in database.");
// 	}

// 	dataMap[key] = fvalue;
	
// }

// double BitcoinExchange::getExchangeRate(const std::string &date) const {}
