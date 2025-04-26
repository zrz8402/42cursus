/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:35:25 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/26 10:58:57 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
Validate Date
    Year
    Month & Date
        2 -> 28/29
        1, 3, 5, 7, 8, 10, 12 -> 31
        4, 6, 9, 11 -> 30
Validate Value
    0 ~ 100

Find match date
Multiple value * rate
*/