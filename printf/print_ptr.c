/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:45:18 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/14 09:24:47 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	count_ptr(uintptr_t nb)
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

static	void	put_ptr(uintptr_t nb)
{
	if (nb > 15)
	{
		put_ptr((nb / 16));
		put_ptr((nb % 16));
	}
	else
	{
		if (nb > 9)
			ft_putchar_fd((nb - 10 + 'a'), 1);
		else
			ft_putchar_fd((nb % 16 + '0'), 1);
	}
}

int	print_ptr(uintptr_t nb)
{
	if (nb == 0)
		return (print_str("(nil)"));
	write(1, "0x", 2);
	put_ptr(nb);
	return (count_ptr(nb) + 2);
}
