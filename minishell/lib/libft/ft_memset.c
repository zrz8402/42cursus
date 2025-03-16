/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:37:08 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/01 17:22:20 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// FUNCTION ft_memset (recreate libc function)
/**
 * @brief Fill memory with a constant byte.
 * 
 * The original function is part of the <string.h> standard library.
 * The memset() function fills the first n bytes of the memory area pointed to
 *  by s with the constant byte c.
 * 
 * @param s A pointer.
 * @param c An int that represents the constant byte to use.
 * @param n The number of bytes of memory to fill.
 * @return A pointer to the memory area s.
 * 
 * @note No external dependencies allowed.
 */
//void	*memset(void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
