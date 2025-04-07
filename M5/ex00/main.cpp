/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:17:21 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/06 20:23:24 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

	std::cout << GREEN << "===========TEST OVERLOAD OSTREAM=========== " << RESET << std::endl;
	
	Bureaucrat	*defaultBureaucrat = new Bureaucrat();
	Bureaucrat	*paramBureaucrat = new Bureaucrat("John", 50);
	Bureaucrat	*copyBureaucrat = new Bureaucrat(*paramBureaucrat);
	
	std::cout << *defaultBureaucrat << std::endl;
	std::cout << *paramBureaucrat << std::endl;
	std::cout << *copyBureaucrat << std::endl;


	std::cout << GREEN << "===========TEST INCREMENT/DECREMENT GRADE & EXCEPTION=========== " << RESET << std::endl;

	try
	{
		paramBureaucrat->incrementGrade();
		std::cout << *paramBureaucrat << std::endl;
		defaultBureaucrat->decrementGrade(); // <--- exception catched
		std::cout << *defaultBureaucrat << std::endl;	
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "===========TEST DEEP COPY=========== " << RESET << std::endl;
	
	*defaultBureaucrat = *paramBureaucrat; // <----- deep copy

	std::cout << *defaultBureaucrat << std::endl;
	std::cout << *paramBureaucrat << std::endl;

	defaultBureaucrat->incrementGrade();
	std::cout << *defaultBureaucrat << std::endl;
	std::cout << *paramBureaucrat << std::endl;

	delete defaultBureaucrat;
	delete paramBureaucrat;
	delete copyBureaucrat;

	return (0);
}