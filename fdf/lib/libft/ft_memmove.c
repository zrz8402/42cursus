/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:28:31 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/04 08:53:06 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*n_dst;
	const unsigned char	*n_src;

	n_dst = (unsigned char *)dest;
	n_src = (const unsigned char *)src;
	if (n_src == n_dst)
		return (dest);
	if (n_src > n_dst)
	{
		while (n--)
			*n_dst++ = *n_src++;
	}
	else
	{
		while (n--)
			*(n_dst + n) = *(n_src + n);
	}
	return (dest);
}
