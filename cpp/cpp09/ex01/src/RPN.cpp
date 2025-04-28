/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:35:39 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/26 10:37:59 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &other) {
    stack = other.stack;
}

RPN& RPN::operator=(RPN const &other) {
    if (this != &other) {
        stack = other.stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::is_operator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::is_digit(const std::string &token) {
    return token.length() == 1 && token[0] >= '0' && token[0] <= '9';
}

int RPN::operate(int a, int b, const std::string &op) {
    if (op == "+") {
        return a + b;
    }
    if (op == "-") {
        return a - b;
    }
    if (op == "*") {
        return a * b;
    }
    if (op == "/") {
        if (b == 0) {
            throw std::runtime_error("Error: division by zero");
        }
        return a / b;
    }
    throw std::runtime_error("Error: invalid operator");
}

void RPN::process_expression(const std::string &expr) {
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (is_digit(token)) {
            stack.push(token[0] - '0');
        } else if (is_operator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: not enough operands");
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result = operate(a, b, token);
            stack.push(result);
        } else {
            throw std::runtime_error("Error: invalid token");
        }
    }
    if (stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression");
    }
    std::cout << stack.top() << std::endl;
}