/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:04:30 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 18:44:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
#define __CURE_HPP__

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class ICharacter;

class Cure : AMateria{

protected:
	std::string	type;

public:
	Cure( void );
	Cure( const Cure &other);
	Cure& operator=( const Cure &other );
	~Cure( void );

	std::string const & getType( void ) const;
	
	virtual Cure*	clone( void ) const;
	virtual void	use(ICharacter& target);
};

#endif