/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:23:17 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/16 16:28:59 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iomanip>
#include <sstream>

class ScalarConverter {

private:
	ScalarConverter( void );
	ScalarConverter( ScalarConverter const &other );
	ScalarConverter& operator=( ScalarConverter const &other );
	~ScalarConverter( void );

public:
	static void	convert(std::string const &literal);

private:
	static void	convertToChar(double value);
	static void	convertToInt(double value);
	static void	convertToFloat(double value);
	static void	convertToDouble(double value);
};

#endif