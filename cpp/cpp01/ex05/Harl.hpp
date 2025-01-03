/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:13:55 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/03 16:17:01 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>

class Harl {

private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

public:
	void	complain( std::string level );

};

#endif