/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:38:38 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 12:42:19 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// FUNCTION ft_strncmp (recreate libc function)
/**
 * @brief Compare two strings (up to n bytes).
 * 
 * The original function is part of the <string.h> standard library.
 * The return value is the arithmetic result of subtracting the last compared
 *  byte in s2 from the last compared byte in s1.
 * The comparison stops when a difference is found, or if a string NUL
 *  terminator is found (verify).
 * 
 * @param s1 Pointer to string1.
 * @param s2 Pointer to string 2.
 * @param n The number of bytes to compare.
 * @return 0 if s1==s2.
 * @return A negative value if s1<s2.
 * @return A positive value if s1>s2 (only looking at the first n bytes).
 * 
 * @note No external dependencies allowed.
 */
//int		strncmp(const char *s1, const char *s2, size_t n);
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	us1;
	unsigned char	us2;
	int				diff;

	i = 0;
	while (i < n)
	{
		us1 = (unsigned char)s1[i];
		us2 = (unsigned char)s2[i];
		if (us1 != us2)
		{
			diff = us1 - us2;
			return (diff);
		}
		if (us1 == 0 && us2 == 0)
			return (0);
		i++;
	}
	return (0);
}
