/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:05:00 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/04 12:01:15 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.hpp"
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>


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
	
	utils::splitDataOnMap(dataCsv, _exchangeRates);
	// displayExchange(); // Display the exchange rates
	processLine(inputFile);
	dataCsv.close();
	inputFile.close();
}

void BitcoinExchange::processLine(std::ifstream &filename) {
	std::string content;
	bool header = false;
	while(std::getline(filename, content)) {
		if (utils::trim(content).compare("date | value") == 0 && !header) {
			header = true;
			continue;
		} else if (utils::trim(content).compare("date | value") == 0 && header) {
			std::cerr << RED << "Error: Invalid header line in input file." << RESET << std::endl;
			continue;
		}
		if (utils::invalidDate(content))
			continue;
		if (utils::invalidValue(content))
			continue;
		std::string date = utils::trim(content.substr(0, content.find('|')));
		double value = std::strtod(utils::trim(content.substr(content.find('|') + 1)).c_str(), NULL);
		this->getExchangeRate(date, value);
	}
	
}

void BitcoinExchange::getExchangeRate(const std::string &date, double value) const {
	std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);
	if (it->first != date) {
		
		if (date > _exchangeRates.rbegin()->first) {
			std::cout << std::fixed << std::setprecision(2) << date << " => " << value * _exchangeRates.rbegin()->second << " 💲" << std::endl;
			return;
		}		
		if (it == _exchangeRates.begin()) {
			std::cerr << RED << "Error: No exchange rate found for date => " << date << RESET << std::endl;
			return;
		}
		--it;
	}
	double exchangeRate = it->second;
	std::cout << std::fixed << std::setprecision(2) << date << " => " << value * exchangeRate << " 💲" << std::endl;
	
}

void	BitcoinExchange::displayExchange() const {
	std::map<std::string, double>::const_iterator it = _exchangeRates.begin();
	std::map<std::string, double>::const_iterator end = _exchangeRates.end();
	for (; it != end; ++it) {
		std::cout << std::fixed << std::setprecision(2) << it->first << " => " << it->second << std::endl;
	}
}

// double BitcoinExchange::getExchangeRate(const std::string &date) const {}
