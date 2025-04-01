/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:04:59 by sben-tay          #+#    #+#             */
/*   Updated: 2025/03/25 15:42:32 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {

public:

	MateriaSource( void );
	MateriaSource( const MateriaSource & src );
	virtual ~MateriaSource( void );	
	MateriaSource & 	operator=(const MateriaSource & rhs);

	void 		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);

private:

	AMateria	*array[4];
};

