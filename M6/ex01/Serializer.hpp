/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:39:18 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/23 13:48:17 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include <cstdlib>

#include "Data.hpp"

class Serializer
{
public:

	static uintptr_t serialize(Data *ptr);
	static Data 	*deserialize(uintptr_t raw);

private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &rhs);
};

#endif