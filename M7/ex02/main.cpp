/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:26:24 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/25 20:26:16 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int main()
{
	try {
	
	
	int * a = new int();
	std::cout << *a << std::endl;
	delete a;

	std:: cout << BLUE << "==== test template string ====" << RESET << std::endl;
	Array<std::string> instance1(3);

	instance1[0] = "Hello";
	instance1[1] = "World";
	instance1[2] = "!";
	// instance1[3] = "!" ; // This will throw an exception

	for(unsigned int i = 0; i < instance1.size(); i++)
		std::cout << instance1[i] << " ";
	std::cout << std::endl;


	std:: cout << BLUE << "==== test template integers ====" << RESET << std::endl;
	Array<int> instance2(3);
	instance2[0] = 1;
	instance2[1] = 2;
	instance2[2] = 3;
	// instance2[3] = 4;



	for(unsigned int i = 0; i < instance2.size(); i++)
		std::cout << instance2[i] << " ";
	std::cout << std::endl;

	std:: cout << BLUE << "==== test template float ====" << RESET << std::endl;
	Array<float> instance3(3);

	instance3[0] = 1.1f;
	instance3[1] = 2.2f;
	instance3[2] = 3.3f;
	// instance3[3] = 4.4f;

	for(unsigned int i = 0; i < instance3.size(); i++)
		std::cout << instance3[i] << "f" << " ";
	std::cout << std::endl;

	std:: cout << BLUE << "==== test template char ====" << RESET << std::endl;
	Array<char> instance4(3);
	instance4[0] = 'a';
	instance4[1] = 'b';
	instance4[2] = 'c';
	// instance4[3] = 'd';

	for(unsigned int i = 0; i < instance4.size(); i++)
		std::cout << instance4[i] << " ";
	std::cout << std::endl;


	std:: cout << BLUE << "==== test deep copy and constructor of copy ====" << RESET << std::endl;

	Array<std::string> instance5(instance1);
	
	std::cout << RED << "instance5 : " << RESET;
	for(unsigned int i = 0; i < instance5.size(); i++)
		std::cout << instance5[i] << " ";
	std::cout << std::endl;

	
	instance5[0] = "Goodbye";
	
	std::cout << RED << "instance5: " << RESET;
	for(unsigned int i = 0; i < instance5.size(); i++)
		std::cout << instance5[i] << " ";
	std::cout << std::endl;
	
	std::cout << RED << "instance1: " << RESET;
	for(unsigned int i = 0; i < instance1.size(); i++)
		std::cout << instance1[i] << " ";
	std::cout << std::endl;
	
	} catch(std::exception & e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
}