/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:37:02 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/01 16:49:19 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// FUNCTION ft_memmove (recreate libc function)
/**
 * @brief Copy memory area (overlaps allowed).
 * 
 * The original function is part of the <string.h> standard library.
 * The  memmove()  function  copies  n bytes from memory area src to memory area
 *  dest. 
 * The memory areas may overlap: copying takes place as though the bytes in src
 *  are first copied into a temporary array that does not overlap src or dest,
 *  and the bytes are then copied from the temporary array to dest.
 * 
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of byte to copy from src to dest.
 * @return A pointer to the dest memory area.
 * 
 * @note No external dependencies allowed.
 */
//void	*memmove(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src < dest && (src + n) > dest)
	{
		i = n;
		while (i > 0)
		{
			((char *)dest)[i - 1] = ((char *)src)[i - 1];
			i--;
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
