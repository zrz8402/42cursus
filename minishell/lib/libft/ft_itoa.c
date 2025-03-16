/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 01:17:34 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/01 17:21:35 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_int_chars(int n);
static void	fill_int_string(int n, char *intstr, int strlen);

// FUNCTION ft_itoa (novel function)
/**
 * @brief Convert a positive or negative integer into an ASCII string.
 * 
 * Allocates with malloc() and returns a string representing the integer received
 *  as an argument. Negative numbers must be handled.
 * 
 * @param n The integer to convert.
 * @return The string representing the integer.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *ft_itoa(int n);
char	*ft_itoa(int n)
{
	int		strlen;
	char	*intstr;

	strlen = count_int_chars(n);
	intstr = (char *)malloc(sizeof(char) * (strlen + 1));
	if (intstr == 0)
		return (0);
	fill_int_string(n, intstr, strlen);
	return (intstr);
}

// Helper function - count characters needed for integer string
static int	count_int_chars(int n)
{
	int	c;
	int	rem;

	c = 0;
	rem = n;
	if (rem == -2147483648)
		return (11);
	if (rem < 0)
	{
		rem = rem * -1;
		c++;
	}
	while (rem >= 10)
	{
		rem = rem / 10;
		c++;
	}
	c++;
	return (c);
}

// Helper function - fill new string with characters matching integer
static void	fill_int_string(int n, char *intstr, int strlen)
{
	int	rem;
	int	sig;
	int	i;

	if (n == -2147483648)
	{
		ft_strlcpy(intstr, "-2147483648", 12);
		return ;
	}
	sig = 1;
	rem = n;
	if (rem < 0)
		sig = -1;
	rem = rem * sig;
	i = strlen - 1;
	while (rem >= 10)
	{
		intstr[i] = rem % 10 + '0';
		rem = rem / 10;
		i--;
	}
	intstr[i] = rem + '0';
	if (sig < 0)
		intstr[0] = '-';
	intstr[strlen] = 0;
}
