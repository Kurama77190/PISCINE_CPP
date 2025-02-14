/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:04:58 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/14 13:58:48 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Wrong number of arguments"	<< std::endl;
	}
	else
	{
		std::string filename = argv[1];
		std::string	s1 = argv[2];
		std::string s2 = argv[3];

		std::ifstream inFile(filename.c_str());
		if (!inFile.is_open())
    		std::cerr << "Error: cannot open " << filename << std::endl;

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
}

