/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:28:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 12:12:12 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal {

protected:
	std::string	type;

public:
	Animal( void );
	Animal( std::string type );
	Animal( const Animal &other );
	Animal& operator=( const Animal &other );
	virtual ~Animal( void );

	std::string		getType( void ) const;
	virtual void	makeSound( void ) const;
};

#endif