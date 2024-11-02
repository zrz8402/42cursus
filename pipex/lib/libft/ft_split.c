/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:34:02 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/12 10:10:45 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **s, int i)
{
	while (i >= 0)
		free(s[i--]);
	free(s);
	return (NULL);
}

static char	**fillstrs(char **strs, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] != c && s[i])
			i++;
		strs[j] = ft_substr(s, start, i - start);
		if (!strs[j])
			return (ft_free(strs, j));
		j++;
	}
	strs[j] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	strs = malloc((count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (count)
		strs = fillstrs(strs, s, c);
	else
		strs[0] = 0;
	return (strs);
}
