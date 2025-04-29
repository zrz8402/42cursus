/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:39:12 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/29 09:56:52 by ruzhang          ###   ########.fr       */
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
#include <list>
#include <vector>

class PmergeMe {

private:
    static void    binaryInsertDeque(std::deque<int> &sorted, int value);
    static void    binaryInsertVector(std::vector<int> &sorted, int value);
    static void    binaryInsertList(std::list<int> &sorted, int value);

public:
    PmergeMe();
    PmergeMe(PmergeMe const &other);
    PmergeMe& operator=(PmergeMe const &other);
    ~PmergeMe();

    static std::deque<int> sortDeque(const std::deque<int> &numbers);
    static void    printDeque(std::deque<int> numbers);

    static std::vector<int> sortVector(const std::vector<int> &numbers);
    static void    printVector(std::vector<int> numbers);

    static std::list<int> sortList(const std::list<int> &numbers);
    static void    printList(std::list<int> numbers);
};

#endif