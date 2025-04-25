/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:06:41 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/25 20:23:12 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::string	arr2[] = {"Hello", "World", "!"};
	
	int length = sizeof(arr) / sizeof(arr[0]);
	int length2 = sizeof(arr2) / sizeof(arr2[0]);
	
	
	std::cout << BLUE << "==== test template integers ====" << RESET << std::endl;
	iter(arr, length, printElement<int>);
	std::cout << std::endl;
	
	std::cout << BLUE << "==== test template string ====" << RESET << std::endl;
	iter(arr2, length2, printElement<std::string>);
	std::cout << std::endl;

	return (0);
}
