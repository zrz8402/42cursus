/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:38:18 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 13:28:12 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// FUNCTION ft_strlcat (recreate libc function)
/**
 * @brief Size-bounded string concatenation.
 * 
 * The original function is part of the <string.h> standard library.
 * Appends the NUL-terminated string src to the end of dst.  It will append at
 *  most size - ft_strlen(dst) - 1 bytes, NUL-terminating the result.
 * Takes the full size of the buffer (not just the length) and guarantee to
 *  NUL-terminate the result (as long as size is larger than 0, or as long as
 *  there is at least one byte free in dst).
 * Note that a byte for the NUL should be included in size.
 * Note both src and dst must be NUL-terminated (true C strings).
 * Note if strlcat() traverses size characters without finding a NUL, the length
 *  of the string is considered to be size and the destination string will not
 *  be NUL-terminated (since there was no space for the NUL).  This keeps
 *  strlcat() from running off the end of a string.  In practice this should not
 *  happen (as it means that either size is incorrect or that dst is not a
 *  proper “C” string).
 * 
 * @param dst A pointer to the destination string.
 * @param src A pointer to the source string.
 * @param size The full size of the buffer (including the NUL byte).
 * @return The total length of the string it tried to create (the length of dst
 *  plus the length of src); this is to make truncation detection simple. 
 * 
 * @note No external dependencies allowed.
 */
//size_t strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	desti;
	size_t	i;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	desti = ft_strlen(dst);
	i = 0;
	while (size > (desti + i + 1) && src[i] != 0)
	{
		dst[desti + i] = src[i];
		i++;
	}
	dst[desti + i] = 0;
	return (desti + ft_strlen(src));
}
