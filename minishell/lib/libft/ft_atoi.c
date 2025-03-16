/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:28:13 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 16:50:05 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// FUNCTION ft_atoi (recreate libc function)
/**
 * @brief Convert an ASCII string of numbers to an integer.
 * 
 * The original function is part of the <stdlib.h> standard library.
 * Converts the initial portion of the string pointed to by nptr (stopping at
 *  the null-terminator or the first non-digit character) to int.
 * The string may begin with an arbitrary amount of white space (as determined by
 *  isspace(3)) followed by a single optional '+' or '-' sign.
 * No checks for overflow or underflow are done.
 * Only base-10 input can be converted.
 * 
 * @param nptr A pointer to a string.
 * @return The converted value.
 * @return 0 on error (note there is no way to distinguish between 0 as an error
 *  and as a converted value).
 * 
 * @note No external dependencies allowed.
 */
//int		atoi(const char *nptr);
int	ft_atoi(const char *str)
{
	int		integer;
	int		sig;
	size_t	i;

	integer = 0;
	sig = 1;
	i = 0;
	while (str[i] != 0
		&& ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		integer = integer * 10 + (str[i] - '0');
		i++;
	}
	return (integer * sig);
}
