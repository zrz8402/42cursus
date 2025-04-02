/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:04:33 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 14:43:09 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
#define __ICE_HPP__

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria{

public:
	Ice( void );
	Ice( const Ice &other);
	Ice& operator=( const Ice &other );
	virtual	~Ice( void );
	
	Ice*	clone( void ) const;
	void	use(ICharacter& target);
};

#endif