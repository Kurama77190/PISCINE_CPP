/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:36:37 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/27 15:38:32 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		Animal* meta[4];

		Dog*	A = new Dog();
		Cat*	B = new Cat();

		for (int i = 0; i < 4; i++)
		{
			if ( i % 2 == 0)
				meta[i] = new Dog();
			else
				meta[i] = new Cat();
		}
		B->setBrainIdeas(100, "I HAVE IDEA");
		B->setBrainIdeas(99, "I HAVE IDEA");

		std::cout << " idea test: " << B->getBrainIdeas(100) << std::endl;
		std::cout << " idea test: " << B->getBrainIdeas(99) << std::endl;
		std::cout << " idea test: " << B->getBrainIdeas(98) << std::endl;

		for (int i = 0; i < 4; i++)
			delete meta[i];
		delete A;
		delete B;

	}
	return 0;
}
