/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:37:42 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/11 14:31:42 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return ((char *) &s[i]);
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return ((char *) &s[i]);
	}
	return (NULL);
}
