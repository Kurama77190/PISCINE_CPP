/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:03:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/03 17:46:02 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange exchange;
		exchange.loadDatabase(std::string(argv[1]));
		std::cout << "Database loaded successfully." << std::endl;
		
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
