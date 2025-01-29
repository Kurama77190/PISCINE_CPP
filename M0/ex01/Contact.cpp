/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:44:04 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/29 22:10:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact( void ) : _index(1), _firstname("SAMY"), _lastname("BENTAYEB"), _nickname("ANNULLEDMITE"), \
						   _phone_number("0668343719"), _darkest_secret("IM A ROBOT")
{
	return ;
}

Contact::~Contact( void )
{
	return ;
}

std::string	_resize_str( std::string str )
{
	if (str.size() > 10)
	{
		str.resize(9);
		str += ".";
	}
	return (str);
}

void Contact::displayContact() const
{
	
	std::cout	<< std::setw(10) << _resize_str(this->_firstname) << "|"
				<< std::setw(10) << _resize_str(this->_lastname) << "|"
				<< std::setw(10) << _resize_str(this->_nickname) << "|"
				<< std::setw(10) << _resize_str(this->_phone_number) << "|" << std::endl;
}
