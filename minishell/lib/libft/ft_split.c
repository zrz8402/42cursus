/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:41:58 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 17:32:00 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_substrings(char const *s, char c);
static char	**make_arr(char const *s, char **subsarr, int *sstart, int *slen);
static void	loc_substrings(char const *s, char c, int *sstart, int *slen);
static void	copy_substring(char *dest, const char *s, int sstart, int slen);

// FUNCTION ft_split (novel function)
/**
 * @brief Splits a string into multiple substrings based on a delimiter.
 * 
 * Allocates with malloc() and returns an array of strings obtained by splitting
 *  ‘s’ using the character ‘c’ as a delimiter. The array must end with a NULL
 *  pointer.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() and free() from <stdlib.h>.
 */
//char **ft_split(char const *s, char c);
char	**ft_split(char const *s, char c)
{
	char	**subsarr;
	int		*sstart;
	int		*slen;
	int		nsubs;

	if (!s)
		return (0);
	nsubs = count_substrings(s, c);
	sstart = (int *)malloc(sizeof(int) * (nsubs + 2));
	if (!sstart)
		return (0);
	slen = (int *)malloc(sizeof(int) * (nsubs + 2));
	if (!slen)
		return (0);
	loc_substrings(s, c, sstart, slen);
	subsarr = 0;
	subsarr = make_arr(s, subsarr, sstart, slen);
	free(sstart);
	free(slen);
	return (subsarr);
}

// Helper function - count substrings
static int	count_substrings(char const *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (s[i] != 0)
			n++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (n);
}

// Helper function - locate substrings
static void	loc_substrings(char const *s, char c, int *sstart, int *slen)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i] != 0)
			i++;
		sstart[n] = i;
		while (s[i] != c && s[i] != 0)
			i++;
		slen[n] = i - sstart[n];
		n++;
	}
	sstart[n] = 0;
	slen[n] = 0;
}

// Helper function - create arrays
static char	**make_arr(char const *s, char **subsarr, int *sstart, int *slen)
{
	int	n;
	int	nsubs;

	nsubs = 0;
	while (slen[nsubs] != 0)
		nsubs++;
	subsarr = (char **)malloc(sizeof(char *) * (nsubs + 1));
	if (subsarr == 0)
		return (0);
	n = 0;
	while (n < nsubs)
	{
		subsarr[n] = (char *)malloc(sizeof(char) * (slen[n] + 1));
		if (subsarr[n] == 0)
		{
			while (n >= 0)
				free(subsarr[n--]);
			free(subsarr);
			return (0);
		}
		copy_substring(subsarr[n], s, sstart[n], slen[n]);
		n++;
	}
	subsarr[n] = NULL;
	return (subsarr);
}

// Helper function - copy substring into array
static void	copy_substring(char *dest, char const *s, int sstart, int slen)
{
	int	i;

	i = 0;
	while (i < slen)
	{
		dest[i] = s[sstart + i];
		i++;
	}
	dest[i] = 0;
}
