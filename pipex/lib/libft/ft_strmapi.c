/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:33:17 by ruzhang           #+#    #+#             */
/*   Updated: 2024/08/28 12:50:49 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strmap;
	unsigned int	i;

	strmap = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!strmap)
		return (NULL);
	i = 0;
	while (s[i])
	{
		strmap[i] = f(i, s[i]);
		i++;
	}
	strmap[i] = '\0';
	return (strmap);
}

// char	isodd_tolower(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return (ft_toupper(c));
// 	else
// 		return (ft_tolower(c));
// }
