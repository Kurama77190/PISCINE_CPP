/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:44:10 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/31 19:15:39 by sben-tay         ###   ########.fr       */
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
			if (std::stoi(prompt) < 0 || std::stoi(prompt) > 8 || std::stoi(prompt) >= this->_size_contact)
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

void	Phonebook::getListcontact( void ) const
{
	std::string prompt;
	
	std::cout	<< std::setw(10) << "INDEX" << "|"
				<< std::setw(10) << "FIRSTNAME" << "|"
				<< std::setw(10) << "LASTNAME" << "|"
				<< std::setw(10) << "NICKNAME" << "|" << std::endl;
	for (int i = 0; i < this->_size_contact; i++)
	{
		if (this->_size_contact == 0)
		{
			std::cout << "List Empty please." << std::endl;
			return ;
		}
		this->_listContact[i].getContact();
	}
}


int	Phonebook::setNewContact( void )
{
	std::string prompt;

	if (this->_index == 8)
		this->_index = 0;
	std::cout << "$PHONEBOOK: Enter Firstname : ";
	getline(std::cin, prompt);
	if (std::cin.eof())
		return (ERROR);
	this->_listContact[_index].setContact(prompt, "firstname", 0);
	this->_listContact[_index].setContact(_resize_str(prompt), "resized_firstname", 0);
	std::cout << "$PHONEBOOK: Enter Lastname : ";
	getline(std::cin, prompt);
	if (std::cin.eof())
		return (ERROR);
	this->_listContact[_index].setContact(prompt, "lastname", 0);
	this->_listContact[_index].setContact(_resize_str(prompt), "resized_lastname", 0);
	std::cout << "$PHONEBOOK: Enter Nickname : ";
	getline(std::cin, prompt);
	if (std::cin.eof())
		return (ERROR);
	this->_listContact[_index].setContact(prompt, "nickname", 0);
	this->_listContact[_index].setContact(_resize_str(prompt), "resized_nickname", 0);
	std::cout << "$PHONEBOOK: Enter Phone Number : ";
	getline(std::cin, prompt);
	if (std::cin.eof())
		return (ERROR);
	this->_listContact[_index].setContact(prompt, "phonenumber", 0);
	this->_listContact[_index].setContact(_resize_str(prompt), "resized_phonenumber", 0);
	std::cout << "$PHONEBOOK: Enter Darkest Secret : ";
	getline(std::cin, prompt);
	if (std::cin.eof())
		return (ERROR);
	this->_listContact[_index].setContact(prompt, "darkestsecret", this->_index);
	this->_listContact[_index].setContact(_resize_str(prompt), "resized_darkestsecret", this->_index);
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
