/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:04:24 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/04 11:18:06 by sben-tay         ###   ########.fr       */
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

# define RED "\033[31m"
# define RESET "\033[0m"

class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	
	void loadDatabase(std::string filename);
	void displayExchange() const;
	void processLine(std::ifstream &filename);
	void getExchangeRate(const std::string &date, double value) const;
	private:
	std::map<std::string, double> _exchangeRates;
};

#endif