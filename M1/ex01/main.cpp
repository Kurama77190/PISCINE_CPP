/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:09:39 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/17 18:56:55 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main ( void )
{
	Zombie* array = zombieHorde(-1, "samy");
	if (!array)
		return (1);
	else
	{
		delete[] array;
	}
	return (0);

}
