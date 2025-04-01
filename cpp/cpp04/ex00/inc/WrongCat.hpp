/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:00:26 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 15:58:07 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat( void );
	WrongCat( std::string type );
	WrongCat( const WrongCat &other );
	WrongCat& operator=( const WrongCat &other );
	virtual ~WrongCat( void );

	void	makeSound( void ) const;
};

#endif