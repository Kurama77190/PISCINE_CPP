/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:29:20 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/23 18:05:24 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"


Base::~Base( void ){};

Base *generate( void )
{
	srand(time(0));
	int random = rand() % 3;
	Base *p = NULL;

	if (random == 0)
		p = new A();
	else if (random == 1)
		p = new B();
	else if ( random == 2)
		p = new C();
	else
		throw Base::generateException();
	return (p);
}

void identify( Base* p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		throw Base::identifyException();
}

void identify( Base& p )
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {
		std:: cout << "type A : " << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {
		std:: cout << "Type B : " << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {
		std:: cout << "Type C : " << e.what() << std::endl;
	}	
}
