/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:35:28 by kmartin           #+#    #+#             */
/*   Updated: 2024/02/26 21:39:42 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FUNCTION ft_isalnum (recreate libc function)
/**
 * @brief Checks for an alphanumeric character.
 * 
 * The original function is part of the <ctype.h> standard library.
 * Equivalent to (isalpha(c) || isdigit(c)).
 * 
 * @param c An int; must have value of an unsigned char or EOF.
 * @return The values returned are nonzero if the character c falls into the
 *  tested class.
 * @return  Zero if not.
 * 
 * @note No external dependencies allowed.
 */
//int isalnum(int c);
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
		return (8);
	return (0);
}
