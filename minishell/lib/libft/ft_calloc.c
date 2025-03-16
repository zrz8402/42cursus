/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:35:18 by kmartin           #+#    #+#             */
/*   Updated: 2024/05/03 14:05:05 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stddef.h>
#include <stdint.h>

// FUNCTION ft_calloc (recreate libc function)
/**
 * @brief Allocate memory for an array.
 * 
 * The original function is part of the <stdlib.h> standard library.
 * Allocates memory for an array of nmemb elements of size bytes each and
 *  returns a pointer to the allocated memory.  The memory is set to zero.
 * The original function can fail with an error ‘ENOMEM Out of memory’ under some
 *  conditions.
 * 
 * @param nmemb The number of elements in the array.
 * @param size The number of bytes needed for each element of the array.
 * @return If nmemb or size is 0, then returns either NULL, or a unique pointer
 *  value that can later be successfully passed to free().
 * @return If nmemb x size would result in integer overflow, then returns an
 *  error (NULL).
 * Otherwise, returns a pointer to the allocated memory.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//void	*calloc(size_t nmemb, size_t size);
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memall;

	if (nmemb > 0 && size > 0 && (nmemb > SIZE_MAX / size))
		return (NULL);
	memall = malloc(nmemb * size);
	if (memall == 0)
		return (NULL);
	ft_bzero(memall, nmemb * size);
	return (memall);
}
