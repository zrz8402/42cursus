/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:53:02 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 12:45:04 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// FUNCTION ft_strlcpy (recreate libc function)
/**
 * @brief Size-bounded string copying.
 * 
 * The original function is part of the <string.h> standard library.
 * Copies up to size - 1 characters from the NUL-terminated string src to dst,
 *  NUL-terminating the result.
 * Takes the full size of the buffer (not just the length) and guarantee to
 *  NUL-terminate the result (as long as size is larger than 0).
 * Note that a byte for the NUL should be included in size.
 * Note src must be NUL-terminated (a true C string).
 * 
 * @param dst A pointer to the destination string.
 * @param src A pointer to the source string.
 * @param size The full size of the buffer (including the NUL byte).
 * @return The total length of the string it tried to create (the length of
 *  src); this is to make truncation detection simple. 
 * 
 * @note No external dependencies allowed.
 */
//size_t strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < (size - 1) && src[i] != 0 && size != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = 0;
	return (ft_strlen(src));
}
