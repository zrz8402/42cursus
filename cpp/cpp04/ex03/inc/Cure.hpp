/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:04:30 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 11:16:28 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
#define __CURE_HPP__

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria{

public:
	Cure( void );
	Cure( const Cure &other);
	Cure& operator=( const Cure &other );
	~Cure( void );
	
	Cure*	clone( void ) const;
	void	use(ICharacter& target);
};

#endif