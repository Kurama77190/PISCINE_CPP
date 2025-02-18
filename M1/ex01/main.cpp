/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:09:39 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/18 15:33:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main ( void )
{
	Zombie* array = zombieHorde(std::numeric_limits<int>::max(), "samy");
	if (!array)
		return (1);
	else
	{
		delete[] array;
	}
	return (0);

}
