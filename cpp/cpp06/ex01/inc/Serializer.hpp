/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:44:37 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/17 12:13:43 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer{

private:
	Serializer( void );
	Serializer( Serializer const &other );
	Serializer& operator=( Serializer const &other );
	~Serializer( void );

public:
	static uintptr_t	serialize( Data* ptr );
	static Data* 		deserialize( uintptr_t raw );
};

#endif