/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:51:08 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/18 16:17:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (name == "")
	{
		std::cerr << "Error: param name is empty." << std::endl;
		return (NULL);
	}
	if (N < 0 || N > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: the number of zombies is not valid." << std::endl;
		return (NULL);
	}
	Zombie *horde = new(std::nothrow) Zombie[N];
	if (!horde)
	{
		std::cerr << "Error: std::bad_alloc *horde" << std::endl;
		return (NULL);
	}

	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
		horde[i].announce();
	}
	return (&horde[0]);
}
