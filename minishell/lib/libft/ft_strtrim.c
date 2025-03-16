/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:13:02 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/01 17:27:58 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	loc_substr(char const *s1, char const *set, int *start, int *len);
static int	match_char_set(char const c, char const *set);

// FUNCTION ft_strtrim (novel function)
/**
 * @brief Trims a string with reference to a set of characters to remove from the
 *  start and end.
 * 
 * Allocates with malloc() and returns a copy of ‘s1’ with the characters
 *  specified in ‘set’ removed from the beginning and the end of the string.
 * 
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *ft_strtrim(char const *s1, char const *set);
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		substart;
	int		sublen;	

	substart = 0;
	sublen = ft_strlen(s1);
	loc_substr(s1, set, &substart, &sublen);
	trimmed = ft_substr(s1, substart, sublen);
	return (trimmed);
}

// Helper function - locate substring
static void	loc_substr(char const *s1, char const *set, int *start, int *len)
{
	int	slen;	
	int	i;

	slen = ft_strlen(s1);
	i = 0;
	while (match_char_set(s1[i], set) == 1 && s1[i] != 0)
		i++;
	*start = i;
	if (*start == slen)
	{
		*len = 0;
		return ;
	}
	i = slen - 1;
	while (match_char_set(s1[i], set) == 1 && i > 0)
		i--;
	*len = i - *start + 1;
}

// Helper function - check for match to character set
static int	match_char_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
