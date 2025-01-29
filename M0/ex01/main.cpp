/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:49 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/29 14:40:59 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Class.phonebook.hpp"
#include "Class.contact.hpp"

int main( void )
{
	std::string prompt;
	Contact instance1;
	Phonebook istance2;

	while(1)
	{
		std::cout << "$PHONEBOOK: ";
		getline(std::cin, prompt);
		if (prompt == "EXIT")
		{
			break ;
		}
		if (prompt == "ADD")
		{
			//void
		}
		if (prompt == "SEARCH")
		{
			//void
		}
	}
	return (0);
}