/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:38:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/29 10:05:07 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

// std::deque<int>::iterator customLowerBound(std::deque<int>::iterator first, std::deque<int>::iterator last, int value) {
//     while (first < last) {
//         auto mid = first + (last - first) / 2;
//         // comparisonCount++;
//         if (*mid < value)
//             first = mid + 1;
//         else
//             last = mid;
//     }
//     return first;
// }

void    PmergeMe::binaryInsertDeque(std::deque<int> &sorted, int value) {
    std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    // std::deque<int>::iterator pos = customLowerBound(sorted.begin(), sorted.end(), value);
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
        binaryInsertDeque(sorted, pend[i]);
    }

    return (sorted);
}

void    PmergeMe::printDeque(std::deque<int> numbers) {
    for (std::deque<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << ((it + 1 == numbers.end()) ? "" : " ");
    }
    std::cout << std::endl;
}

void    PmergeMe::binaryInsertVector(std::vector<int> &sorted, int value) {
    std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

std::vector<int> PmergeMe::sortVector(const std::vector<int> &numbers) {
    if (numbers.size() <= 1) {   
        return numbers;
    }

    std::vector<int> main;
    std::vector<int> pend;

    // Step 1: Pairing and Splitting
    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (i + 1 < numbers.size()) {
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
    std::vector<int> sorted = sortVector(main);

    // Step 3: Insert the Pending Elements Using Binary Insertion
    for (size_t i = 0; i < pend.size(); ++i) {
        binaryInsertVector(sorted, pend[i]);
    }

    return (sorted);
}

void    PmergeMe::printVector(std::vector<int> numbers) {
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << ((it + 1 == numbers.end()) ? "" : " ");
    }
    std::cout << std::endl;
}

void    PmergeMe::binaryInsertList(std::list<int> &sorted, int value) {
    std::list<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

std::list<int> PmergeMe::sortList(const std::list<int> &numbers) {
    if (numbers.size() <= 1) {   
        return numbers;
    }

    std::list<int> main;
    std::list<int> pend;

    // Step 1: Pairing and Splitting
    std::list<int>::const_iterator it = numbers.begin();
    while (it != numbers.end()) {
        int first = *it;
        ++it;
        if (it != numbers.end()) {
            int second = *it;
            ++it;
            if (first > second) {
                main.push_back(first);
                pend.push_back(second);
            } else {
                main.push_back(second);
                pend.push_back(first);
            }
        } else {
            pend.push_back(first);
        }
    }

    // Step 2: Recursively Sort the Main Sequence
    std::list<int> sorted = sortList(main);

    // Step 3: Insert the Pending Elements Using Binary Insertion
    std::list<int>::const_iterator tmp;
    for (tmp = pend.begin(); tmp != pend.end(); ++tmp) {
        binaryInsertList(sorted, *tmp);
    }

    return (sorted);
}

void    PmergeMe::printList(std::list<int> numbers) {
    std::list<int>::const_iterator it = numbers.begin();
    while (it != numbers.end()) {
        std::cout << *it;
        std::list<int>::const_iterator next = it;
        ++next;
        if (next != numbers.end()) {
            std::cout << " ";
        }
        ++it;
    }
    std::cout << std::endl;
}
