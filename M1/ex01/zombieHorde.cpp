/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:51:08 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/17 18:58:26 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 0 || N > std::numeric_limits<int>::max())
	{
		std::cout << "Error: the number of zombies is not valid." << std::endl;
		return (NULL);
	}
	try
	{
		Zombie *horde = new Zombie[N];

		for (int i = 0; i < N; i++)
		{
			horde[i].setName(name);
			horde[i].announce();
		}
		return (&horde[0]);
	}
	catch (const std::bad_alloc)
	{
		std::cerr << "Error: Bad_alloc detected." << '\n';
	}
	return (NULL);
}
