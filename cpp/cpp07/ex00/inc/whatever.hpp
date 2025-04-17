/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:04:22 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/17 16:23:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

template <typename T>
void	swap(T &a, T &b) {
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T &a, T &b) {
	return (a < b) ? a : b;
}

template <typename T>
T	max(T &a, T &b) {
	return (a > b) ? a : b;
}

#endif