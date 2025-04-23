/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:42:51 by sben-tay          #+#    #+#             */
/*   Updated: 2025/04/23 13:48:49 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"


Serializer::Serializer(){};
Serializer::~Serializer(){};
Serializer::Serializer(const Serializer &src){*this = src;};
Serializer &Serializer::operator=(const Serializer &rhs){ (void)rhs; return (*this);}


Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
