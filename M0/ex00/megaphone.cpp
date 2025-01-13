/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:43:20 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/14 00:14:27 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main(int argc, char **argv)
{
	int		i = 1;
	std::string str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (argv[i])
		{
			str = argv[i];
			std::transform(str.begin(), str.end(), str.begin(), (int(*)(int))std::toupper);
			if (i < argc - 1)
			std::cout << str << " ";
			else
				std::cout << str << std::endl;
			i++;
		}
	}
	return (0);
}
