/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:12:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/18 10:52:57 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T, typename F>
void	iter(T *array, size_t length, F func) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

#endif