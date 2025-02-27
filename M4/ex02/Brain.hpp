/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 02:14:04 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 14:47:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include <new>

class Brain {

public:

	Brain( void );
	Brain( const Brain & src );
	virtual ~Brain();

	std::string	getIdeas( int index ) const;
	void		setIdeas( int index, std::string idea );
	Brain &		operator=( const Brain & rhs);
	
protected:

	std::string	ideas[100];

};

#endif