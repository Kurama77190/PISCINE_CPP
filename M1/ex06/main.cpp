/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:48:51 by sben-tay          #+#    #+#             */
/*   Updated: 2025/08/17 15:52:02 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main( int argc, char **argv )
{
	Harl instance;

	if (argc != 2)
	{
		std::cerr << "[ Usage: ./harlFilter <level> ]" << std::endl;
		return (1);
	}

	std::string level[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	std::string args = argv[1];

	int idx = -1;
	for(int i = 0; i < 4; i++)
	{
		if (args == level[i])
		{
			idx = i;
			break;
		}
	}

	switch(idx)
	{
		case 0:
			instance.complain("DEBUG");
			std::cout << std::endl;
			//break;
		case 1:
			instance.complain("INFO");
			std::cout << std::endl;
			//break;
		case 2:
			instance.complain("WARNING");
			std::cout << std::endl;
			//break;
		case 3:
			instance.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
			return (1);
	}
	return (0);
}
