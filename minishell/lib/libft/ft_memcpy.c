/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:36:55 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/01 16:24:41 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// FUNCTION ft_memcpy (recreate libc function)
/**
 * @brief Copy memory area (overlaps not allowed).
 * 
 * The original function is part of the <string.h> standard library.
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap.
 * 
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of byte to copy from src to dest.
 * @return A pointer to the dest memory area.
 * 
 * @note No external dependencies allowed.
 */
//void	*memcpy(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
