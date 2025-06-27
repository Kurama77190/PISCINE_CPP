/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:52:00 by sben-tay          #+#    #+#             */
/*   Updated: 2025/06/27 15:09:46 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"


int main() {
	try {
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	/*
		advanced tests
	*/
	
	try {
		MutantStack<char> charStack;
		charStack.push('a');
		charStack.push('b');
		charStack.push('c');
	
		MutantStack<char>::iterator charIt = charStack.begin();
		MutantStack<char>::iterator charEnd = charStack.end();
		MutantStack<char>::const_iterator constCharIt = charStack.begin();
		MutantStack<char>::const_iterator constCharIte = charStack.end();
		MutantStack<char>::reverse_iterator reverseCharIt = charStack.rbegin();
		MutantStack<char>::reverse_iterator reverseCharEnd = charStack.rend();
		MutantStack<char>::const_reverse_iterator constReverseCharIt = charStack.rbegin();
		MutantStack<char>::const_reverse_iterator constReverseCharEnd = charStack.rend();

		++charIt;
		--charIt;
		std::cout << "Iterating through char stack:" << std::endl;
		while (charIt != charEnd)
		{
			std::cout << *charIt << std::endl;
			++charIt;
		}
		std::cout << "Iterating through const char stack:" << std::endl;
		while (constCharIt != constCharIte)
		{
			std::cout << *constCharIt << std::endl;
			++constCharIt;
		}
		std::cout << "Iterating through reverse char stack:" << std::endl;
		while (reverseCharIt != reverseCharEnd)
		{
			std::cout << *reverseCharIt << std::endl;
			++reverseCharIt;
		}
		std::cout << "Iterating through reverse char stack:" << std::endl;
		while (constReverseCharIt != constReverseCharEnd)
		{
			std::cout << *constReverseCharIt << std::endl;
			++constReverseCharIt;
		}
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
