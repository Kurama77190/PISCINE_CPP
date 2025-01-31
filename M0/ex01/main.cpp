/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:53:49 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/31 19:12:41 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Class.phonebook.hpp"
#include "Class.contact.hpp"

int main( void )
{
	std::string prompt;
	Phonebook instance;

	while(1)
	{
	if (std::cin.eof())
		break ;
		std::cout << "$PHONEBOOK: ";
		getline(std::cin, prompt);
		if (prompt == "EXIT")
		{
			break ;
		}
		if (prompt == "ADD")
		{
			if (instance.setNewContact() == ERROR)
				break ;
		}
		if (prompt == "SEARCH")
		{
			instance.getListcontact();
			if (instance.moreDetails() == ERROR)
				break ;
		}
	}
	return (0);
}
