/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:05:00 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/30 18:34:33 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <map>

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
	std::getline(dataCsv, line);
	while (std::getline(dataCsv, line)) {
		this->_exchangeRates = utils::splitDataOnMap(line, ',');
		displayExchange(); // Display the exchange rates
		// processLine(line); // need learn subject
	}
	dataCsv.close();
	inputFile.close();
}

void BitcoinExchange::processLine(const std::string &line) {
	(void)line;
}

void	BitcoinExchange::displayExchange() const {
	std::map<std::string, double>::const_iterator it = _exchangeRates.begin();
	std::map<std::string, double>::const_iterator end = _exchangeRates.end();
	for (; it != end; ++it) {
		std::cout << it->first << " => " << it->second << " " << it->second << std::endl;
	}
}

// double BitcoinExchange::getExchangeRate(const std::string &date) const {}
