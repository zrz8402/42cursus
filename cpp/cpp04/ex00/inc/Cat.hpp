/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:29:10 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 12:43:29 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal {

public:
	Cat( void );
	Cat( std::string type );
	Cat( const Cat &other );
	Cat& operator=( const Cat &other );
	virtual ~Cat( void );

	void	makeSound( void ) const;
};

#endif