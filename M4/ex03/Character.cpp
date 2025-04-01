/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:32:43 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/31 17:12:51 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string name ): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
    for (int i = 0; i < 1024; i++)
        this->backup[i] = NULL;
}

Character::~Character( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
    for (int i = 0; i < 1024; i++)
    {
        if (this->backup[i])
            delete this->backup[i];
    }
}

Character::Character(const Character& src)
{
	*this = src;
}

Character& Character::operator=(const Character& rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i])
            {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
            if (rhs.inventory[i])
                this->inventory[i] = rhs.inventory[i]->clone();
        }
        for (int i = 0; i < 1024; i++)
        {
            if (this->backup[i])
            {
                delete this->backup[i];
                this->backup[i] = NULL;
            }
            if (rhs.backup[i])
                this->backup[i] = rhs.backup[i]->clone();
        }
    }
    return *this;
}

    
std::string const & Character::getName( void ) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << RED << "you can't equip this materia." << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
    {
        if (m && !this->inventory[i])
        {
            this->inventory[i] = m;
            break ;
        }
		if (i == 3)
		{
			std::cout << RED << "Can't equip materia : " << m->getType() << " because inventory is full" << RESET << std::endl;
			delete m;
		}
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !this->inventory[idx])
    {
        std::cerr << RED << "Error : Invalid index" << RESET << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->backup[i] == NULL)
        {
            this->backup[i] = this->inventory[idx];
            this->inventory[idx] = NULL;
            break ;
        }
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !this->inventory[idx])
    {
        std::cout << RED << target.getName() <<" can't use Materia because he was not found" << RESET << std::endl;
        return ;
    }
    this->inventory[idx]->use(target);
}
