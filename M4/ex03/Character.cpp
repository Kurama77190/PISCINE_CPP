/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:32:43 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/28 19:54:54 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string name ): _name(name)
{
};
Character::~Character( void )
{
};

std::string const & Character::getName( void )
{
	return (this->_name);
}
void equip(AMateria* m);
void unequip(int idx);

void Character::use(int idx, ICharacter& target)
{
};