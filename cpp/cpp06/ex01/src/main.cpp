/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:02:51 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/17 12:16:41 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main() {
	Data	data;

	data.planet = "Earth";
	data.satellite = "Moon";

	std::cout << "original " << &data << std::endl;
	std::cout << "planet: " << data.planet << ", satellite: " << data.satellite << std::endl;
	std::cout << std::endl;

	uintptr_t	raw = Serializer::serialize(&data);
	Data*		newData = Serializer::deserialize(raw);

	std::cout << "deserialized " << newData << std::endl;
	std::cout << "planet: " << newData->planet << ", satellite: " << newData->satellite << std::endl;
}
