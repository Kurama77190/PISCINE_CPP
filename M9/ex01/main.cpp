/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:22:54 by sben-tay          #+#    #+#             */
/*   Updated: 2025/07/17 18:39:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments. Usage: ./rpn \"expression\"" << std::endl;
		return 1;
	}
	try {
			
		RPN stack;
		
		stack.evaluate(argv[1]);
		stack.displayStack();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}


	