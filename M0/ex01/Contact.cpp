/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:44:04 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/29 15:18:49 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact( void )
{
	return ;
}

Contact::~Contact( void )
{
	return ;
}

void	_resize_str( std::string str )
{
	if (str.size() > 10);
	{
		str.resize(9);
		str += ".";
	}
}
void Contact::getContact( std::string nb_contact) const
{
	
	std::cout << this->_nickname._resize_str();
}
