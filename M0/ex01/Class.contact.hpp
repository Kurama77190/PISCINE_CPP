/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.contact.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:31:39 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/29 22:06:02 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP
#include <string>

class Contact{

public:

	Contact( void );
	~Contact( void );
	
	void	displayContact() const;

private:

	int			_index;
	std::string _firstname;
	std::string	_lastname;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	std::string	_rezise_str( std::string str );
};

#endif