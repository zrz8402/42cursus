/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:05:01 by ruzhang           #+#    #+#             */
/*   Updated: 2025/01/03 17:24:52 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./harlFilter LEVEL" << std::endl;
		return 0;
	}

	Harl	harl;
	harl.complain(av[1]);

	return 0;
}