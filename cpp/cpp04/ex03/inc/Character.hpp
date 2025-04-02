/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:02:54 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 15:20:35 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {

protected:
	static const int	slots = 4;
	AMateria			*inventory[slots];
	std::string			name;
	

public:
	Character( void );
	Character( const std::string &name );
	Character( const Character &other );
	Character& operator=( const Character &other );
	virtual ~Character( void );

	std::string const & getName( void ) const;

	void	equip( AMateria* m );
	void	unequip( int idx );
	void	use( int idx, ICharacter& target );
};

#endif