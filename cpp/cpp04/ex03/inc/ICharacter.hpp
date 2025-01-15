/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:20:33 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 17:42:28 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICHARACTER_HPP__
#define __ICHARACTER_HPP__

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter {

public:
	virtual ~ICharacter( void ) {}

	virtual std::string const & getName( void ) const = 0;

	virtual void	equip( AMateria* m ) = 0;
	virtual void	unequip( int idx ) = 0;
	virtual void	use( int idx, ICharacter& target ) = 0;
};

#endif