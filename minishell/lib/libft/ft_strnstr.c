/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:38:45 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/01 08:51:50 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// FUNCTION ft_strnstr (recreate libc function)
/**
 * @brief Locate a substring in a defined initial portion of a string.
 * 
 * The original function is part of the <string.h> standard library.
 * Locates the first occurrence of the null-terminated string little in the
 *  string big, where not more than len characters are searched.
 * Characters that appear after a ‘\0’ character are not searched.
 * 
 * @param big A pointer to the string to be searched.
 * @param little A pointer to the null-terminated substring to find.
 * @param len The maximum number of characters to search.
 * @return If little is an empty string, big is returned.
 * @return If little occurs nowhere in big, NULL is returned.
 * @return If little is found it its entirety, a pointer to the first character
 *  of the first occurrence of little is returned.
 * 
 * @note No external dependencies allowed.
 * 
 */
//char *strnstr(const char *big, const char *little, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	litlen;

	litlen = ft_strlen(little);
	if (litlen == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != 0)
	{
		if (litlen > (len - i))
			break ;
		if (ft_strncmp(&big[i], little, litlen) == 0)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
