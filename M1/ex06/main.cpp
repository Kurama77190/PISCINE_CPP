/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:48:51 by sben-tay          #+#    #+#             */
/*   Updated: 2025/08/11 10:44:34 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main( int argc, char **argv )
{
	Harl instance;

	if (argc != 2)
		std::cerr << "[ Usage: ./harlFilter <level> ]" << std::endl;
	std::string args = argv[1];
	if (args == "DEBUG")
	{
		instance.complain(args);
		std::cout << std::endl;
		instance.complain("INFO");
		std::cout << std::endl;
		instance.complain("WARNING");
		std::cout << std::endl;
		instance.complain("ERROR");
	}
	else if (args == "INFO")
	{
		instance.complain(args);
		std::cout << std::endl;
		instance.complain("WARNING");
		std::cout << std::endl;
		instance.complain("ERROR");
	}
	else if (args == "WARNING")
	{
		instance.complain(args);
		std::cout << std::endl;
		instance.complain("ERROR");
	}
	else if (args == "ERROR")
	{
		instance.complain(args);
	}
	else
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	std::cout << std::endl;
	return (0);
}
