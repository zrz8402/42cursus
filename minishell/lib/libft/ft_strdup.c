/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:38:03 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 13:58:23 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

// FUNCTION ft_strdup (recreate libc function)
/**
 * @brief Duplicate a string.
 * 
 * The original function is part of the <string.h> standard library.
 * Memory for the duplicate string is obtained with malloc(), and can be freed
 *  with free().
 * 
 * @param s A pointer to a string.
 * @return A pointer to a new string which is a duplicate of the string s.
 * @return If insufficient memory is available, returns NULL and sets errno to
 *  indicate the cause of the error (‘ENOMEM’; insufficient memory available to
 *  allocate duplicate string).
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *strdup(const char *s);
char	*ft_strdup(const char *s)
{
	char	*dupstr;
	size_t	len;

	len = ft_strlen(s);
	dupstr = malloc(len + 1);
	if (dupstr == 0)
		return (0);
	ft_strlcpy(dupstr, s, len + 1);
	return (dupstr);
}
