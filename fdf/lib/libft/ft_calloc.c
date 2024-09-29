/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:34:45 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/26 13:11:12 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;
	size_t	i;

	if (nmemb != 0 && nmemb * size / nmemb != size)
		return (0);
	i = nmemb * size;
	tmp = malloc(i);
	if (!tmp)
		return (0);
	return (ft_memset(tmp, 0, i));
}
