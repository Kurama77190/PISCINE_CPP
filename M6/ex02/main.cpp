/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:44:17 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/23 18:15:48 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

class D : public Base {
public:
	virtual ~D( void ) {};
};

# define BLUE "\033[1;34m"
# define RESET "\033[0m"

int main()
{
	std::cout << BLUE << "test identify(&p) with instance generate" << RESET << std::endl;
	try {
		Base *base = generate();
		identify(base);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << BLUE << "test identify(&p) with Class D" << RESET << std::endl;
	try {
		Base *base = new D();
		identify(base);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << BLUE << "test identify(&r) with instance generate" << RESET << std::endl;
	try {
		Base *base = generate();
		identify(*base);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << BLUE << "test identify(&r) with class D" << RESET << std::endl;
	try {
		Base *base = new D();
		identify(*base);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	
	return 0;
}
