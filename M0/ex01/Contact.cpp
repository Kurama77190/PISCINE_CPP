/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:44:04 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/06 16:41:32 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>


Contact::Contact( void ) : _index(0), _firstname(""), _lastname(""), _nickname(""), \
						   _phoneNumber(""), _darkestSecret("")
{
	return ;
}

Contact::~Contact( void )
{
	return ;
}

std::string Contact::getFirstname( int flag ) const
{
	if (flag == 1)
		return (this->_Resized_firstname);
	return (this->_firstname);
}

std::string Contact::getLastname( int flag ) const
{
	if (flag == 1)
		return (this->_Resized_lastname);
	return (this->_lastname);
}

std::string Contact::getNickname( int flag ) const
{
	if (flag == 1)
		return (this->_Resized_nickname);
	return (this->_nickname);
}

std::string Contact::getPhoneNumber( int flag ) const
{
	if (flag == 1)
		return (this->_Resized_phoneNumber);
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret( int flag ) const
{
	if (flag == 1)
		return (this->_Resized_DarkestSecret);
	return (this->_darkestSecret);
}


void Contact::getContact( void ) const
{
	std::cout	<< "|" << std::setw(10) << this->_index << "|"
				<< std::setw(10) << getFirstname(1) << "|"
				<< std::setw(10) << getLastname(1) << "|"
				<< std::setw(10) << getNickname(1) << "|\n"
				<< "+----------+----------+----------+----------+" << std::endl;
}

void	Contact::getDetailsContact( void ) const
{
	std::cout	<< "\n\ndetails of [" << getFirstname(0) << "]\n\n"
				<< "Firstname: " << getFirstname(0) << "\n"
				<< "Lastname: " << getLastname(0) << "\n"
				<< "Nickname: " << getNickname(0) << "\n"
				<< "Phone number: " << getPhoneNumber(0) << "\n"
				<< "Darkest Secret : " << getDarkestSecret(0) << "\n" << std::endl;
				
}	

void	Contact::setContact( std::string data, std::string varName, int	i)
{
	if (i == 8)
		i = 0;
	if (varName == "firstname")
		this->_firstname = data;
	if (varName == "lastname")
		this->_lastname = data;
	if (varName == "nickname")
		this->_nickname = data;
	if (varName == "phonenumber")
		this->_phoneNumber = data;
	if (varName == "darkestsecret")
		this->_darkestSecret = data;
	if (varName == "resized_firstname")
		this->_Resized_firstname = data;
	if (varName == "resized_lastname")
		this->_Resized_lastname = data;
	if (varName == "resized_nickname")
		this->_Resized_nickname = data;
	if (varName == "resized_phonenumber")
		this->_Resized_phoneNumber = data;
	if (varName == "resized_darkestsecret")
		this->_Resized_DarkestSecret = data;
	this->_index = i;
	return ;
}
