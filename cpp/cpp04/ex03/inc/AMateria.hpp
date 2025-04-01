/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:17:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 18:21:42 by ruzhang          ###   ########.fr       */
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
	~AMateria( void );

	std::string const & getType( void ) const;	// provided; Returns the materia type
	
	// return a new instance of the same type
	virtual AMateria*	clone( void ) const = 0;	// provided
	virtual void		use(ICharacter& target);	// provided
	// Display:
	// Ice: "* shoots an ice bolt at <name> *"
	// Cure: "* heals <name>’s wounds *"
};

#endif