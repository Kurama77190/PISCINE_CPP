/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:44:36 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/23 18:19:17 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"


# define BLUE "\033[1;34m"
# define RESET "\033[0m"

int main( void )
{
	Data data;

	data.s1 = "Hello";
	data.n = 42;

	std::cout << BLUE << "Original Data:" << RESET << std::endl;
	std::cout << "Adress Data : " << &data << std::endl;
	std::cout << "s1: " << data.s1 << std::endl;
	std::cout << "n: " << data.n << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << BLUE << "Adress Data after Serializer : " << &data << RESET << std::endl;
	// raw += 1; // This line crashes the program because it modifies the address.

	Data *data_ptr = Serializer::deserialize(raw);
	std::cout << BLUE << "Data after Deserialize: " << RESET << std::endl;
	std::cout << "Adress Data : " << data_ptr << std::endl;

	std::cout << "s1: " << data_ptr->s1 << std::endl;
	std::cout << "n: " << data_ptr->n << std::endl;

}
