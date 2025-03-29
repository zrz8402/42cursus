/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:00:32 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/29 15:50:10 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );

void randomChump( std::string name );

int	main(void){
	{
		Zombie zombie("Kate");
		zombie.announce();
	}

	Zombie *zombie1 = newZombie("Ron");
	zombie1->announce();
	delete zombie1;

	randomChump("Rocket");
}
