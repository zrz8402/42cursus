/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:51:07 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/11 14:35:44 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*n_dst;
	const unsigned char	*n_src;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	n_dst = (unsigned char *)dest;
	n_src = (const unsigned char *)src;
	while (n--)
		*n_dst++ = *n_src++;
	return (dest);
}
