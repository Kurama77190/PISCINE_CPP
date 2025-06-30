/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:04:24 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/30 16:45:19 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <string>
# include <stdexcept>
class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	
	void loadDatabase(std::string filename);
	double getExchangeRate(const std::string &date) const;
	void processLine(const std::string &line);

	private:
	std::multimap<std::string, double> _exchangeRates;
};

// void parseLineToMap(const std::string &line, std::map<std::string, double> &dataMap, char separator) {
// 	std::string key;
// 	std::string value;
// 	std::size_t pos = line.find(separator);

// 	if (pos == std::string::npos)
// 		throw std::invalid_argument("Error: Invalid line format in database.");

// 	key = line.substr(0, pos);
// 	value = line.substr(pos + 1);

// 	// Conversion en double
// 	// double fvalue = std::atof(value.c_str());
// 	if (fvalue < 0) {
// 		throw std::invalid_argument("Error: Negative value in database.");
// 	}

// 	dataMap[key] = fvalue;
// }

#endif