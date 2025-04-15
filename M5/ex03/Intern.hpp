/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:38:54 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/15 19:49:38 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Intern
{
public:
	Intern( void );
	Intern( const Intern & src );
	~Intern( void );
	Intern & operator=( Intern const & rhs );

	AForm * makeForm(std::string formName, std::string target);
	
	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form not found!";
		}
	};

private:
	std::string	_formNames[3];
	AForm *		(Intern::*_formConstructors[3])(std::string target);
	AForm *		makeShrubberyCreationForm(std::string target);
	AForm *		makeRobotomyRequestForm(std::string target);
	AForm *		makePresidentialPardonForm(std::string target);
};

#endif