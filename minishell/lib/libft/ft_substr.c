/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:57:39 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/06 12:44:20 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

// FUNCTION ft_substr (novel function)
/**
 * @brief Extracts a substring of a given length from a given start position.
 * 
 * Allocates with malloc() and returns a substring from the string s.
 * The substring begins at index ‘start’ and is of maximum size ‘length’.
 * 
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string s.
 * @param len The maximum length of the string.
 * @return The substring.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	sublen;
	size_t	strlen;
	size_t	i;

	strlen = ft_strlen(s);
	sublen = 0;
	while (start < strlen && sublen < len && s[sublen + start] != 0)
		sublen++;
	substr = (char *)malloc(sizeof(char) * (sublen + 1));
	if (substr == 0)
		return (0);
	i = 0;
	while (i < sublen)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[sublen] = 0;
	return (substr);
}
