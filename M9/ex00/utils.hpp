/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:17:37 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/30 16:30:07 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <map>
# include <stdexcept>


namespace utils {
	
	bool postFix(const std:: string &str);
	bool isValidDate(const std::string &date);
	bool emptyFile(const std::string &filename);
}

#endif