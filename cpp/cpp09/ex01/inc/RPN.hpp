/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:35:33 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/26 10:37:45 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN {

private:
    std::stack<int> stack;

    bool is_operator(const std::string &token);
    bool is_digit(const std::string &token);
    int operate(int a, int b, const std::string &op);

public:
    RPN();
    RPN(RPN const &other);
    RPN& operator=(RPN const &other);
    ~RPN();

    void process_expression(const std::string &expr);
};

#endif