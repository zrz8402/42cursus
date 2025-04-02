/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:17:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 14:33:26 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

protected:
	std::string	type;

public:
	AMateria( void );
	AMateria( const std::string & type );	// provided
	AMateria( const AMateria &other);
	AMateria& operator=( const AMateria &other );
	virtual	~AMateria( void );

	// Returns the materia type
	std::string const & getType( void ) const;	// provided; 
	
	// return a new instance of the same type
	virtual AMateria*	clone( void ) const = 0;	// provided
	virtual void		use(ICharacter& target);	// provided
};

#endif