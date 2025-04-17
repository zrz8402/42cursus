/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:45:30 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/17 12:02:37 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {}

Serializer::Serializer( Serializer const &other ) {
	*this = other;
}

Serializer& Serializer::operator=( Serializer const &other ) {
	if (this != &other) {}
	return *this;
}

Serializer::~Serializer( void ) {}

uintptr_t	Serializer::serialize( Data* ptr ) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* 	Serializer::deserialize( uintptr_t raw ) {
	return reinterpret_cast<Data*>(raw);
}
