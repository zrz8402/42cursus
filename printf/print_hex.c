/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:20:35 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/14 09:24:33 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned int nb)
{
	int	count;

	count = 1;
	while (nb > 15)
	{
		count++;
		nb /= 16;
	}
	return (count);
}

static	void	put_hex(unsigned int nb, char c)
{
	if (nb > 15)
	{
		put_hex((nb / 16), c);
		put_hex((nb % 16), c);
	}
	else
	{
		if (nb > 9)
		{
			if (c == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			else
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
		else
			ft_putchar_fd((nb % 16 + '0'), 1);
	}
}

int	print_hex(unsigned int nb, char c)
{
	put_hex(nb, c);
	return (count_hex(nb));
}
