/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:36:36 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/01 02:46:17 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// FUNCTION ft_memchr (recreate libc function)
/**
 * @brief Scan memory area for first instance of a character.
 * 
 * The original function is part of the <string.h> standard library.
 * 
 * @param s A pointer to the memory area to search.
 * @param c An int representing the character to search for.
 * @param n The number of bytes of memory to search.
 * @return A pointer to the matching byte or NULL if the character does not
 *  occur in the given memory area.
 * 
 * @note No external dependencies allowed.
 */
//void	*memchr(const void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	s_char;

	i = 0;
	while (i < n)
	{
		s_char = (unsigned char)((char *)s)[i];
		if (s_char == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
