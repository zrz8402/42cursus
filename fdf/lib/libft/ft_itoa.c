/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:32:45 by ruzhang           #+#    #+#             */
/*   Updated: 2024/08/30 12:51:12 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int		count;

	count = 0;
	if (n < 0)
		count++;
	if (n != 0)
	{
		while (n)
		{
			count++;
			n /= 10;
		}
	}
	else
		count = 1;
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				count;
	unsigned int	nb;

	count = ft_count(n);
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (count--)
	{
		str[count] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
