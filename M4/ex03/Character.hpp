/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:28:39 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/27 17:20:21 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTERE_HPP
# define CHARACTERE_HPP

# include "ICharacter.hpp"
#define RED     "\033[31m"
# define RESET   "\033[0m"


class Character: public ICharacter {
public:

	Character( std::string );
	virtual ~Character( void );
	
	Character(const Character& src);
	Character& operator=(const Character& other);

	std::string const & getName( void ) const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:

	AMateria	*backup[1024];
	std::string _name;
	AMateria	*inventory[4];
	size_t		len_backup;
};

#endif