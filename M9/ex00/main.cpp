/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:03:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/28 20:16:53 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <database_file>" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange exchange;
		exchange.loadDatabase(std::string(argv[1]));
		// exchange.printData();

		// std::string date;
		// std::cout << "Enter a date (YYYY-MM-DD): ";
		// std::cin >> date;

		// double value = exchange.getValue(date);
		// std::cout << "Value for " << date << ": " << value << std::endl;
		
	} catch (const std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
	}
}

