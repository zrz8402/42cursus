/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:28:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 17:14:14 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

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