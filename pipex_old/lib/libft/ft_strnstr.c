/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:56:00 by ruzhang           #+#    #+#             */
/*   Updated: 2024/08/27 19:50:35 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		while (little[j] == big[i + j] && (i + j < len) && big[i + j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *) &big[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
