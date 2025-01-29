/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.phonebook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:30:53 by sben-tay          #+#    #+#             */
/*   Updated: 2025/01/29 14:40:15 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

#include "Class.contact.hpp"

class Phonebook{

public:

	Phonebook( void );
	~Phonebook( void );

	void set_contact( void );

private:

	Contact tab_contact[8];

};

#endif