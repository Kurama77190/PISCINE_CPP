/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.phonebook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:30:53 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/05 18:49:39 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP
#include "Class.contact.hpp"

# define SUCCESS 0
#define ERROR 1

class Phonebook{

public:

	Phonebook( void );
	~Phonebook( void );

	int		getListcontact( void ) const;
	int		setNewContact( void );
	int		moreDetails( void );

private:

	int			_setNickname( void );
	int			_setFirstName( void );
	int			_setLastName( void );
	int			_setPhoneNumber( void );
	int			_setDarkestSecret( void );
	int			_check_input( std::string str );
	Contact		_listContact[8];
	int			_size_contact;
	int			_index;

	std::string	_resize_str( std::string str );

};

#endif