/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:26:07 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/15 19:14:05 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm & src );
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );

	void		execute(Bureaucrat const & src) const;
	std::string	getTarget( void ) const;

private:
	std::string	_target;
	ShrubberyCreationForm( void );
};

std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif