/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:27:40 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/07 16:02:10 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie( void ): name("foo")
{
	std::cout << "Default constructor has been called" << std::endl;
}

Zombie::Zombie( std::string name ) : name(name)
{
	std::cout << "Parametric constructor has been called" << std::endl;
}

void	Zombie::Announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << "Destructor has been called" << std::endl;
}
