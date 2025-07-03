/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:17:37 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/03 17:15:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <map>
# include <stdexcept>


namespace utils {
	
	bool postFix(const std:: string &str);
	bool invalidFormat(std::map<std::string, double>::const_iterator it, std::map<std::string, double>::const_iterator end);
	bool emptyFile(const std::string &filename);
	bool invalidDate(const std::string &content);
	bool invalidValue(const std::string &content);
	std::string trim(std::string str);
	
	void splitDataOnMap(std::ifstream &line, std::map<std::string, double> &dataMap);
}

#endif