/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:38:33 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 11:47:20 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// FUNCTION ft_strlen (recreate libc function)
/**
 * @brief Calculate the length of a string.
 * 
 * The original function is part of the <string.h> standard library.
 * 
 * @param s A string.
 * @return The number of bytes in the string pointed to by s.
 * 
 * @note No external dependencies allowed.
 */
//size_t strlen(const char *s);
size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != 0)
	{
		c++;
	}
	return (c);
}
