/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:17:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 17:57:00 by ruzhang          ###   ########.fr       */
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
	AMateria( const std::string & type );
	AMateria( const AMateria &other);
	AMateria& operator=( const AMateria &other );
	~AMateria( void );

	std::string const & getType( void ) const;
	
	virtual AMateria*	clone( void ) const = 0;
	virtual void		use(ICharacter& target);
};

#endif