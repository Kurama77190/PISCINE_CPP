/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:26:13 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/28 22:32:43 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "BitcoinExchange.hpp"

namespace utils {
	// Check if the date is in the format YYYY-MM-DD
	bool isValidDate(const std::string &date);
	// Check if the value is a valid number
	bool isValidValue(const std::string &value);
	// Parse the value from a string to double
	double parseValue(const std::string &value);
	// Trim whitespace from the beginning and end of a string
	std::string trim(const std::string &str);
	// Format the date to YYYY-MM-DD
	std::string formatDate(const std::string &date);
	bool postfix(const std::string &str);
	bool isEmptyFile(const std::string &filename);

}

#endif