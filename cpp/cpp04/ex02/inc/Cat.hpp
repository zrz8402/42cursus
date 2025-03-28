/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:29:10 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 17:00:55 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
 
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