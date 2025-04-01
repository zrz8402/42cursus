/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:02:54 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 18:43:10 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class Character {

private:
	std::string	name;

public:
	Character( void );
	Character( const Character &other);
	Character& operator=( const Character &other );
	virtual ~Character( void ) {}

	virtual std::string const & getName( void ) const;

	virtual void	equip( AMateria* m );
	virtual void	unequip( int idx );
	virtual void	use( int idx, Character& target );
};

#endif