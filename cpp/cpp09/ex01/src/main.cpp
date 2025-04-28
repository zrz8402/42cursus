/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:35:37 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/28 10:16:53 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Usage: ./program <expression>" << std::endl;
        return 1;
    }

    RPN rpn;
    try {
        rpn.process_expression(av[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

/*
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
./RPN "7 7 * 7 -"
42
./RPN "1 2 * 2 / 2 * 2 4 - +"
0
./RPN "(1 + 1)"
Error
*/

/*
2 * (3 + 4)
2 3 4 + *
./RPN "2 3 4 + *"
*/