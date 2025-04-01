/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:00:22 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 15:58:01 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

#include <iostream>

class WrongAnimal {

protected:
	std::string	type;

public:
	WrongAnimal( void );
	WrongAnimal( std::string type );
	WrongAnimal( const WrongAnimal &other );
	WrongAnimal& operator=( const WrongAnimal &other );
	virtual ~WrongAnimal( void );

	std::string		getType( void ) const;
	virtual void	makeSound( void ) const;
};

#endif