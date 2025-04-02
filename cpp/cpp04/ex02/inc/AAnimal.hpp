/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:28:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 13:14:23 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
#define __AANIMAL_HPP__

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

#include <iostream>
#include "Brain.hpp"

class AAnimal {

protected:
	std::string	type;

public:
	AAnimal( void );
	AAnimal( std::string type );
	AAnimal( const AAnimal &other );
	AAnimal& operator=( const AAnimal &other );
	virtual ~AAnimal( void );

	std::string		getType( void ) const;
	virtual void	makeSound( void ) const = 0;
	virtual Brain*	getBrain( void ) const = 0;
};

#endif