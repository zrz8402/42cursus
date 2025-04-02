/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:01:07 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/02 15:33:20 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

protected:
	static const int	slots = 4;
	AMateria			*inventory[slots];

public:
	MateriaSource( void );
	MateriaSource( const MateriaSource &other );
	MateriaSource& operator=( const MateriaSource &other );
	virtual ~MateriaSource( void );

	void		learnMateria( AMateria* materia );
	AMateria*	createMateria( std::string const & type );
};

#endif