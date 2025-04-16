/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:23:19 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/16 16:40:24 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( ScalarConverter const &other ) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=( ScalarConverter const &other ) {
	if (this != &other) {}
	return *this;
}

ScalarConverter::~ScalarConverter( void ) {}

void	ScalarConverter::convert( std::string const &literal ) {
	double		value;
	char		*end = NULL;
	std::string	upperLiteral;

	for (std::string::const_iterator it = literal.begin(); it != literal.end(); ++it) {
		upperLiteral += toupper(*it);
	}

	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		value = static_cast<double>(literal[0]);
	} else {
		if (upperLiteral[upperLiteral.length() - 1] == 'F') {
			value = std::strtod(upperLiteral.substr(0, upperLiteral.length() - 1).c_str(), &end);
		} else {
			value = std::strtod(upperLiteral.c_str(), &end);
		}

		if (*end != '\0') {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
	}

	std::cout << std::fixed << std::setprecision(1);

	convertToChar(value);
	convertToInt(value);
	convertToFloat(value);
	convertToDouble(value);
}

void	ScalarConverter::convertToChar(double value) {
	std::cout << "char: ";

	if (std::isnan(value) || value < 0 || value > 127) {
		std::cout << "impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(value))) {
		std::cout << "non diaplayable" << std::endl;
	} else {
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}
}

void	ScalarConverter::convertToInt(double value) {
	std::cout << "int: ";

	if (std::isnan(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max()) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(value) << std::endl;
	}
}

void	ScalarConverter::convertToFloat(double value) {
	std::cout << "float: ";

	float	f = static_cast<float>(value);

	if (std::isnan(f)) {
		std::cout << "nanf" << std::endl;
	} else if (std::isinf(f)) {
		std::cout << (f < 0 ? "-inff" : "+inff") << std::endl;
	} else {
		std::cout << f << "f" << std::endl;
	}
}

void	ScalarConverter::convertToDouble(double value) {
	std::cout << "double: ";

	if (std::isnan(value)) {
		std::cout << "nan" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
	} else {
		std::cout << value << std::endl;
	}
}
