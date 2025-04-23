/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:24:31 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/23 18:11:54 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <exception>
# include <ctime>

class Base {
public:
	virtual ~Base( void );

	class generateException : public std::exception {
	public:
		virtual const char* what() const throw() {return "generate_failed";}
	};

	class identifyException : public std::exception {
	public:
		virtual const char* what() const throw() {return "identify_failed";}
	};
};


Base *generate( void );
void identify( Base* p );
void identify( Base& p );

#endif
