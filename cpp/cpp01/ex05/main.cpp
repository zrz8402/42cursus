/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:26:07 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/29 17:18:47 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl	harl;

	harl.complain("debug");
	std::cout << std::endl;

	harl.complain("info");
	std::cout << std::endl;

	harl.complain("warning");
	std::cout << std::endl;

	harl.complain("error");
	std::cout << std::endl;

	harl.complain("complain");
}