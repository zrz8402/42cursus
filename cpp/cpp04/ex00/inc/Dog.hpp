/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:29:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 12:43:36 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal {

public:
	Dog( void );
	Dog( std::string type );
	Dog( const Dog &other );
	Dog& operator=( const Dog &other );
	virtual ~Dog( void );

	void	makeSound( void ) const;
};

#endif