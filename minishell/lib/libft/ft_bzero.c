/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:35:05 by kmartin           #+#    #+#             */
/*   Updated: 2024/02/26 21:39:42 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// FUNCTION ft_bzero (recreate libc function)
/**
 * @brief Zero a byte string.
 * 
 * The original function is part of the <strings.h> UNIX library (not the
 *  standard C library).
 * The bzero() function erases the data in the n bytes of the memory starting at
 *  the location pointed to by s, by writing zeros (bytes containing '\0') to
 *  that area.
 * 
 * @param s A pointer to the memory location to be erased.
 * @param n Number of bytes of memory to be erased.
 * @return None.
 * 
 * @note No external dependencies allowed.
 */
//void	bzero(void *s, size_t n);
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
