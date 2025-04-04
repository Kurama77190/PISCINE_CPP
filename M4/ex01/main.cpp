/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:36:37 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/02 15:27:16 by sben-tay         ###   ########.fr       */
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

		Cat* 	C = new Cat();
		Cat*	D = new Cat();


		std::cout << "test deep copy";

		*C = *D;
		C->setBrainIdeas(99, "I HAVE IDEA");
		D->setBrainIdeas(99, "I HAVE IDEA FOR DEEP COPY");

		std::cout << C->getBrainIdeas(99) << std::endl;
		std::cout << D->getBrainIdeas(99) << std::endl;

		delete C;
		delete D;
		std::cout << "end test deep copy";
		
		{
			Cat *other = new Cat(*B);
			other->makeSound();
			std::cout << other->getBrainIdeas(100) << std::endl;
			delete other;
		}

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
