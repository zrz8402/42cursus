/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:58:39 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/04 08:56:43 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sh;

	sh = (unsigned char *)s ;
	while (n > 0)
	{
		if (*sh == (unsigned char)c)
			return ((void *)sh);
		sh++;
		n--;
	}
	return (NULL);
}
