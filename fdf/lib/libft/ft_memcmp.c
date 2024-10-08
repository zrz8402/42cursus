/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:26:12 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/04 08:57:18 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*n_s1;
	const unsigned char	*n_s2;

	n_s1 = (unsigned char *)s1;
	n_s2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*n_s1 != *n_s2)
			return (*n_s1 - *n_s2);
		n--;
		n_s1++;
		n_s2++;
	}
	return (0);
}
