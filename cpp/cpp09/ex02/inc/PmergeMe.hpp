/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:39:12 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/28 13:21:01 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <deque>

class PmergeMe {

public:
    PmergeMe();
    PmergeMe(PmergeMe const &other);
    PmergeMe& operator=(PmergeMe const &other);
    ~PmergeMe();

    static std::deque<int> sortDeque(const std::deque<int> &numbers);
    static void    printDeque(std::deque<int> numbers);
};

#endif