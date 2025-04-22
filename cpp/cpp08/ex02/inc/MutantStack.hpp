/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:01:56 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/22 15:34:21 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>
#include <iostream>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {

public:
    MutantStack( void );
    MutantStack( const MutantStack &other);
    MutantStack& operator=( const MutantStack &other);
    ~MutantStack( void );

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator                begin();
    iterator                end();
    const_iterator          begin() const;
    const_iterator          end() const;
    reverse_iterator        rbegin();
    reverse_iterator        rend();
    const_reverse_iterator  rbegin() const;
    const_reverse_iterator  rend() const;

};


#include "MutantStack.tpp"

#endif

// template <typename T, typename Container = std::deque<T>>
// class MutantStack : public std::stack<T, Container> {

// public:
//     MutantStack( void );
//     MutantStack( const MutantStack &other);
//     MutantStack& operator=( const MutantStack &other);
//     ~MutantStack( void );

//     typedef typename std::stack<T>::container_type::iterator iterator;
//     typedef typename std::stack<T>::container_type::const_iterator const_iterator;
//     typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
//     typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

//     iterator                begin();
//     iterator                end();
//     const_iterator          begin() const;
//     const_iterator          end() const;
//     reverse_iterator        rbegin();
//     reverse_iterator        rend();
//     const_reverse_iterator  rbegin() const;
//     const_reverse_iterator  rend() const;
// };
