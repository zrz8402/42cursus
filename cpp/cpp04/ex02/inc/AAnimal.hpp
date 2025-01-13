/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:28:09 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 17:12:22 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
#define __AANIMAL_HPP__

#include <iostream>

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
};

#endif