/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:44:10 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/06 16:37:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook( void ):	_size_contact(0),
								_index(0)
{
}

Phonebook::~Phonebook( void )
{
}

int		Phonebook::moreDetails( void )
{
	std::string prompt;

	std::cout << "Do you want see more details ? [y][n]" << std::endl;
	while (1)
	{
		getline(std::cin, prompt);
		if (std::cin.eof())
		{
			this->~Phonebook();
			exit(1);
		}
		if (prompt == "y")
		{
			std::cout << "\n\nChoice index contact : ";
			getline(std::cin, prompt);
			if (std::cin.eof())
				return (ERROR);
			if (prompt.empty() || prompt.size() > 2 || std::stoi(prompt) < 0 \
				|| std::stoi(prompt) > 8 || std::stoi(prompt) > this->_size_contact - 1)
			{
				std::cout << "Invalid index." << std::endl;
				return (SUCCESS);
			}
			this->_listContact[std::stoi(prompt)].getDetailsContact();
			return (SUCCESS);
		}
		if (prompt == "n")
			break ;
	}
	return (SUCCESS);
}

int	Phonebook::getListcontact( void ) const
{
	std::string prompt;
	
	if (this->_size_contact == 0)
		{
			std::cout << "List Empty." << std::endl;
			return (ERROR);
		}
	std::cout << "+-------------------------------------------+\n";
    std::cout << "|                PHONEBOOK                  |\n";
    std::cout << "+----------+----------+----------+----------+\n";
	std::cout	<< "|" << std::setw(10) << "INDEX" << "|"
				<< std::setw(10) << "FIRSTNAME" << "|"
				<< std::setw(10) << "LASTNAME" << "|"
				<< std::setw(10) << "NICKNAME" << "|" << std::endl;
				std::cout << "+----------+----------+----------+----------+\n";
	for (int i = 0; i < this->_size_contact; i++)
	{
		this->_listContact[i].getContact();
	}
	return (SUCCESS);
}

int	Phonebook::_setFirstName( void )
{
	std::string prompt;

	while (1)
	{
		std::cout << "$PHONEBOOK: Enter Firstname : ";
		getline(std::cin, prompt);
		if (std::cin.eof())
			return (ERROR);
		if (prompt.empty())
		{
			std::cout << "Firstname is empty. Try again please." << std::endl;
			continue ;
		}
		if (!_isAlpha(prompt))
		{
			std::cout << "Firstname is invalid. Try again please." << std::endl;
			continue ;
		}
		this->_listContact[_index].setContact(prompt, "firstname", 0);
		this->_listContact[_index].setContact(_resize_str(prompt), "resized_firstname", 0);
		break ;
	}
	return (SUCCESS);
}

int	Phonebook::_setLastName( void )
{
	std::string prompt;

	while (1)
	{
		std::cout << "$PHONEBOOK: Enter Lastname : ";
		getline(std::cin, prompt);
		if (std::cin.eof())
			return (ERROR);
		if (prompt.empty())
		{
			std::cout << "Lastname is empty. Try again please." << std::endl;
			continue ;
		}
		if (!_isAlpha(prompt))
		{
			std::cout << "Lastname is invalid. Try again please." << std::endl;
			continue ;
		}
		this->_listContact[_index].setContact(prompt, "lastname", 0);
		this->_listContact[_index].setContact(_resize_str(prompt), "resized_lastname", 0);
		break ;	
	}
	return (SUCCESS);
}

int	Phonebook::_setNickname( void )
{
	std::string prompt;

	while (1)
	{
		std::cout << "$PHONEBOOK: Enter Nickname : ";
		getline(std::cin, prompt);
		if (std::cin.eof())
			return (ERROR);
		if (prompt.empty())
		{
			std::cout << "Nickname is empty. Try again please." << std::endl;
			continue ;
		}
		this->_listContact[_index].setContact(prompt, "nickname", 0);
		this->_listContact[_index].setContact(_resize_str(prompt), "resized_nickname", 0);
		break ;	
	}
	return (SUCCESS);
}

int	Phonebook::_setPhoneNumber( void )
{
	std::string prompt;

	while (1)
	{
		std::cout << "$PHONEBOOK: Enter Phone Number : ";
		getline(std::cin, prompt);
		if (std::cin.eof())
			return (ERROR);
		if (prompt.empty())
		{
			std::cout << "Phone Number is empty. Try again please." << std::endl;
			continue ;
		}
		if (_isNumber(prompt) == false)
		{
			std::cout << "Phone Number is invalid. Try again please." << std::endl;
			continue ;
		}
		this->_listContact[_index].setContact(prompt, "phonenumber", 0);
		this->_listContact[_index].setContact(_resize_str(prompt), "resized_phonenumber", 0);
		break ;	
	}
	return (SUCCESS);
}

int	Phonebook::_setDarkestSecret( void )
{
	std::string prompt;

	while (1)
	{
		std::cout << "$PHONEBOOK: Enter darkest secret : ";
		getline(std::cin, prompt);
		if (std::cin.eof())
			return (ERROR);
		if (prompt.empty())
		{
			std::cout << "Darkest secret is empty. Try again please." << std::endl;
			continue ;
		}
		this->_listContact[_index].setContact(prompt, "darkestsecret", this->_index);
		this->_listContact[_index].setContact(_resize_str(prompt), "resized_darkestsecret", this->_index);
		break ;	
	}
	return (SUCCESS);
}

int	Phonebook::setNewContact( void )
{
	std::string prompt;

	if (this->_index == 8)
		this->_index = 0;
	
	if (this->_setFirstName() == ERROR)
		return (ERROR);
	if (this->_setLastName() == ERROR)
		return (ERROR);
	if (this->_setNickname() == ERROR)
		return (ERROR);
	if (this->_setPhoneNumber() == ERROR)
		return (ERROR);
	if (this->_setDarkestSecret() == ERROR)
		return (ERROR);
	if (_size_contact < 8)
		_size_contact += 1;
	this->_index++;
	return (SUCCESS);
}

std::string	Phonebook::_resize_str( std::string str )
{
	if (str.size() > 10)
	{
		str.resize(9);
		str += ".";
	}
	return (str);
}

bool	Phonebook::_isNumber( std::string prompt )
{
	bool	is_digit = true;

	for (int i = 0; i < prompt.size(); i++)
	{
		if (!std::isdigit((char)prompt[i]) && !std::isspace((char)prompt[i]))
		{
			is_digit = false;
			return (is_digit);
		}
	}
	return (is_digit);
}

bool	Phonebook::_isAlpha( std::string prompt )
{
	bool	is_digit = true;

	for (int i = 0; i < prompt.size(); i++)
	{
		if (!std::isalpha((char)prompt[i]) && !std::isspace((char)prompt[i]))
		{
			is_digit = false;
			return (is_digit);
		}
	}
	return (is_digit);
}
