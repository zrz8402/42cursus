/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:15:15 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/14 09:24:38 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*ft_itoa(int n)
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

int	print_int(int n)
{
	char	*num_to_str;
	int		len;

	num_to_str = ft_itoa(n);
	len = print_str(num_to_str);
	free(num_to_str);
	return (len);
}
