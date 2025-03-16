/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:13:13 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 16:49:29 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

// FUNCTION ft_strjoin (novel function)
/**
 * @brief Concatenates two strings and returns a new string.
 * 
 * Allocates with malloc() and returns a new string, which is the result of the
 *  concatenation of ‘s1’ and ‘s2’.
 * 
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len_1;
	size_t	len_2;
	size_t	strlen;
	size_t	i;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	strlen = len_1 + len_2;
	newstr = malloc(strlen + 1);
	if (newstr == 0)
		return (0);
	i = 0;
	while (i < len_1)
	{
		newstr[i] = s1[i];
		i++;
	}
	while (i <= strlen)
	{
		newstr[i] = s2[i - len_1];
		i++;
	}
	return (newstr);
}
