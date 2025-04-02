/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:01:07 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 13:18:24 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "AMateria.hpp"

class MateriaSource {

protected:
	static const int	slots = 4;
	AMateria			*inventory[slots];

public:
	MateriaSource( void );
	MateriaSource( const MateriaSource &other);
	MateriaSource& operator=( const MateriaSource &other );
	virtual ~MateriaSource( void ) {}

	void		learnMateria( AMateria* );
	AMateria*	createMateria( std::string const & type );
};

#endif