/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:27:12 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/14 09:24:55 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(unsigned int nb)
{
	int	count;

	count = 1;
	while (nb > 9)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static	void	put_unsigned(unsigned int nb)
{
	if (nb > 9)
		put_unsigned(nb / 10);
	ft_putchar_fd((nb % 10 + '0'), 1);
}

int	print_unsigned(unsigned int nb)
{
	put_unsigned(nb);
	return (count_digit(nb));
}
