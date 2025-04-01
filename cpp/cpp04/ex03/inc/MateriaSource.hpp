/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:01:07 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 18:30:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "AMateria.hpp"

class MateriaSource {

public:
	MateriaSource( void );
	MateriaSource( const MateriaSource &other);
	MateriaSource& operator=( const MateriaSource &other );
	virtual ~MateriaSource( void ) {}

	virtual void		learnMateria( AMateria* );
	virtual AMateria*	createMateria( std::string const & type );
};

#endif