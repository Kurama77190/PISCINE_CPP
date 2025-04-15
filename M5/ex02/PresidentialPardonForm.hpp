/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:26:01 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/15 19:12:18 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( const PresidentialPardonForm & src );
	~PresidentialPardonForm( void );
	PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );

	void		execute(Bureaucrat const & executor) const;
	std::string	getTarget( void ) const;
	
private:
	std::string	_target;
	PresidentialPardonForm( void );
};
std::ostream & operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif