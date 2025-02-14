/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:49:50 by sben-tay          #+#    #+#             */
/*   Updated: 2025/02/14 16:09:19 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>




class Harl{

public:

	void	complain( std::string level );
			Harl( void );
			~Harl( void );

private:

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

};


#endif