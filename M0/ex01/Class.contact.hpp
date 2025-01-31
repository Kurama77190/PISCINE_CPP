/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.contact.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:31:39 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/31 18:24:46 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP
#include <string>

class Contact{

public:

	Contact( void );
	~Contact( void );

	std::string	getFirstname( int flag ) const;
	std::string getLastname( int flag ) const;
	std::string getNickname( int flag ) const;
	std::string getPhoneNumber( int flag ) const;
	std::string getDarkestSecret( int flag ) const;

	void		setContact( std::string data, std::string varName, int i);
	void		getContact( void ) const;
	void		getDetailsContact( void ) const;

private:

	int			_index;
	std::string _firstname;
	std::string	_lastname;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

	std::string	_Resized_firstname;
	std::string	_Resized_lastname;
	std::string	_Resized_nickname;
	std::string	_Resized_phoneNumber;
	std::string	_Resized_DarkestSecret;
};

#endif