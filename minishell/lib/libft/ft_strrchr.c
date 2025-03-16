/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:38:54 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 13:41:05 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// FUNCTION ft_strrchr (recreate libc function)
/**
 * @brief Locate single-byte character in string (last occurrence).
 * 
 * The original function is part of the <string.h> standard library.
 * 
 * @param s Pointer to a string.
 * @param c Int representing the character to search for (ASCII byte value).
 * @return NULL if the character is not found.
 * @return A pointer to the matched character. The terminating null byte is
 *  considered part of the string, so that if c is specified as '\0' it will
 *  return a pointer to the terminator.
 * 
 * @note No external dependencies allowed.
 * 
 */
//char *strrchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c)
{
	size_t	strlen;
	int		i ;

	strlen = ft_strlen(s);
	i = strlen;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i = i - 1;
	}
	return (0);
}
