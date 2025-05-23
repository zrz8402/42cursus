/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:38:39 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/29 10:37:47 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <sstream>
#include <algorithm>
#include <iomanip>

bool    isPositive(const std::string &str, int &result) {
    std::istringstream iss(str);
    int     num;
    char    extra;

    if (!(iss >> num) || (iss >> extra)) {
        return false;
    }
    result = num;
    return result > 0;
}

double  getElapseTime(clock_t start, clock_t end) {
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

int main(int ac, char** av) {
    if (ac == 1) {
        std::cerr << "Usage: ./program <expression>" << std::endl;
        return 1;
    }

    // deque
    std::deque<int> numsDeque;
    std::deque<int> sortedDeque;

    clock_t dequeStart;
    clock_t dequeEnd;

    dequeStart = clock();
    for (int i = 1; i < ac; ++i) {
        int value;
        if (!isPositive(av[i], value)) {
            std::cerr << "Error: invalid input" << std::endl;
            return 1;
        }
        numsDeque.push_back(value);
    }
    sortedDeque = PmergeMe::sortDeque(numsDeque);
    dequeEnd = clock();

    // vector
    std::vector<int> numsVector;
    std::vector<int> sortedVector;

    clock_t vectorStart;
    clock_t vectorEnd;

    vectorStart = clock();
    for (int i = 1; i < ac; ++i) {
        int value;
        if (!isPositive(av[i], value)) {
            std::cerr << "Error: invalid input" << std::endl;
            return 1;
        }
        numsVector.push_back(value);
    }
    sortedVector = PmergeMe::sortVector(numsVector);
    vectorEnd = clock();

    // list
    std::list<int> numsList;
    std::list<int> sortedList;

    clock_t listStart;
    clock_t listEnd;

    listStart = clock();
    for (int i = 1; i < ac; ++i) {
        int value;
        if (!isPositive(av[i], value)) {
            std::cerr << "Error: invalid input" << std::endl;
            return 1;
        }
        numsList.push_back(value);
    }
    sortedList = PmergeMe::sortList(numsList);
    listEnd = clock();

    std::cout << "Before: ";
    PmergeMe::printDeque(numsDeque);
    std::cout << "After: ";
    PmergeMe::printDeque(sortedDeque);
    std::cout << std::endl;

    std::cout << "Before: ";
    PmergeMe::printVector(numsVector);
    std::cout << "After: ";
    PmergeMe::printVector(sortedVector);
    std::cout << std::endl;

    std::cout << "Before: ";
    PmergeMe::printList(numsList);
    std::cout << "After: ";
    PmergeMe::printList(sortedList);
    std::cout << std::endl;

    std::cout << "Time to process a range of " << ac - 1 <<" elements with [std::deque]: " << getElapseTime(dequeStart, dequeEnd) << " us" << std::endl;
    std::cout << "Time to process a range of " << ac -1 <<" elements with [std::vector]: " << std::fixed << std::setprecision(5) << getElapseTime(vectorStart, vectorEnd) << " us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 <<" elements with [std::list]: " << std::fixed << std::setprecision(5) << getElapseTime(listStart, listEnd) << " us" << std::endl;

    return 0;
}

/*
./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us

./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us

./PmergeMe "-1" "2"
Error

# For OSX USER:
./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
*/