/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:12:13 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/17 16:40:55 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T, typename Func>
void	iter(T *array, int len, Func function) {
	for (int i = 0; i < len; i++) {
		function(array[i]);
	}
}

#endif