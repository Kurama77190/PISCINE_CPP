/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:53:26 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/18 16:09:33 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_replace.hpp"

int	ft_replace(char *filename_, char *s1_, char *s2_)
{
	if (!*s1_)
	{
		std::cerr << "Error: S1 has empty." << std::endl;
		return (1);
	}
	else
	{
		std::string filename = filename_;
		std::string	s1 = s1_;
		std::string s2 = s2_;

		std::ifstream inFile(filename.c_str());
		if (!inFile.is_open())
		{
    		std::cerr << "Error: cannot open " << filename << std::endl;
			return (1);
		}

		std::string content;
		{
			std::string line;
			std::size_t	pos;
			std::size_t	offset = 0;

			while(std::getline(inFile, line))
			{
				pos = line.find(s1, offset);
				while(pos != std::string::npos)
				{
					line.erase(pos, s1.length());
					line.insert(pos, s2);
					offset = pos + s2.length();
					pos = line.find(s1, offset);
				}
				offset = 0;
				content += line + '\n';
			}
			std::ofstream ofs(filename + ".replace");
			ofs << content;
		}
		inFile.close();
	}
	return (0);
}