/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:38:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/28 14:40:53 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int comparisonCount = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

std::deque<int>::iterator customLowerBound(std::deque<int>::iterator first, std::deque<int>::iterator last, int value) {
    while (first < last) {comparisonCount++;
        auto mid = first + (last - first) / 2;
        comparisonCount++;
        if (*mid < value)
            first = mid + 1;
        else
            last = mid;
    }
    return first;
}

void    binaryInsert(std::deque<int> &sorted, int value) {
    // std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    std::deque<int>::iterator pos = customLowerBound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &numbers) {
    if (numbers.size() <= 1) {   
        return numbers;
    }

    std::deque<int> main;
    std::deque<int> pend;

    // Step 1: Pairing and Splitting
    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (i + 1 < numbers.size()) {
            comparisonCount++;
            if (numbers[i] > numbers[i + 1]) {
                main.push_back(numbers[i]);
                pend.push_back(numbers[i + 1]);
            } else {
                main.push_back(numbers[i + 1]);
                pend.push_back(numbers[i]);
            }
        } else {
            pend.push_back(numbers[i]);
        }
    }

    // Step 2: Recursively Sort the Main Sequence
    std::deque<int> sorted = sortDeque(main);

    // Step 3: Insert the Pending Elements Using Binary Insertion
    for (size_t i = 0; i < pend.size(); ++i) {
        binaryInsert(sorted, pend[i]);
    }

    return (sorted);
}

void    PmergeMe::printDeque(std::deque<int> numbers) {
    for (std::deque<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << ((it + 1 == numbers.end()) ? "" : " ");
    }
    std::cout << std::endl;

    // std::cout << comparisonCount << std::endl;
}
