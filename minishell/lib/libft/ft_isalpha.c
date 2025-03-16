/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:35:38 by kmartin           #+#    #+#             */
/*   Updated: 2024/02/26 21:39:42 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FUNCTION ft_isalpha (recreate libc function)
/**
 * @brief Checks for an alphabetic character.
 * 
 * The original function is part of the <ctype.h> standard library. 
 * Equivalent to (isupper(c) || islower(c)).
 * 
 * @param c An int; must have the value of an unsigned char or EOF.
 * @return The values returned are nonzero if the character c falls into the
 *  tested class.
 * @return  Zero if not.
 * 
 * @note No external dependencies allowed.
 */
//int isalpha(int c);
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	return (0);
}
