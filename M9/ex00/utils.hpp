/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:17:37 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/24 16:56:51 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <map>
# include <stdexcept>


namespace utils {
	
	bool postFix(const std:: string &str);
	bool emptyFile(const std::string &filename);
	bool invalidDate(const std::string &content);
	bool invalidValue(const std::string &content);
	std::string trim(std::string str);
	
	void splitDataOnMap(std::ifstream &line, std::map<std::string, double> &dataMap);
}

#endif