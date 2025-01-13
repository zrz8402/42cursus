/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:00:26 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/13 13:02:06 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat( void );
	WrongCat( std::string type );
	WrongCat( const WrongCat &other );
	WrongCat& operator=( const WrongCat &other );
	virtual ~WrongCat( void );

	void	makeSound( void ) const;
};

#endif