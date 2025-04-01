/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:29:10 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 16:37:19 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
#define __CAT_HPP__

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 
private:
	Brain	*brain;

public:
	Cat( void );
	Cat( const Cat &other );
	Cat& operator=( const Cat &other );
	virtual ~Cat( void );

	void	makeSound( void ) const;
};

#endif