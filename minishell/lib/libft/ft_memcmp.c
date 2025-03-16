/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:36:45 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 12:48:29 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// FUNCTION ft_memcmp (recreate libc function)
/**
 * @brief Compare contents of two memory areas.
 * 
 * The original function is part of the <string.h> standard library.
 * The return value is the arithmetic result of subtracting the last compared
 *  byte in s2 from the last compared byte in s1.
 * The comparison stops when a difference is found.
 * 
 * @param s1 Pointer to memory area 1.
 * @param s2 Pointer to memory area 2.
 * @param n The number of bytes to compare.
 * @return 0 if s1==s2.
 * @return A negative value if s1<s2.
 * @return A positive value if s1>s2 (only taking into account the first n
 *  bytes).
 * 
 * @note No external dependencies allowed.
 */
//int		memcmp(const void *s1, const void *s2, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	s1_c;
	unsigned char	s2_c;
	int				diff;

	i = 0;
	while (i < n)
	{
		s1_c = (unsigned char)((char *)s1)[i];
		s2_c = (unsigned char)((char *)s2)[i];
		if (s1_c != s2_c)
		{
			diff = s1_c - s2_c;
			return (diff);
		}
		i++;
	}
	return (0);
}
