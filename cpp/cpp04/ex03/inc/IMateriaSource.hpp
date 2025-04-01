/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:40:15 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/01 18:01:51 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMATERIASOURCE_HPP__
#define __IMATERIASOURCE_HPP__

#include "AMateria.hpp"

class IMateriaSource {

public:
	virtual ~IMateriaSource( void ) {}	// provided

	virtual void		learnMateria( AMateria* ) = 0;	// provided
	virtual AMateria*	createMateria( std::string const & type ) = 0;	// provided
};

#endif