/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:00:32 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/04 14:23:12 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main(void){
	int			size = 10;
	std::string	name = "Ron";
	Zombie		*zombies = zombieHorde(size, name);

	for (int i = 0; i < size; i++) {
		zombies[i].announce();
	}
	delete[] zombies;
}
