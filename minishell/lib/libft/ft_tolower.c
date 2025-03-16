/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:39:03 by kmartin           #+#    #+#             */
/*   Updated: 2024/02/26 21:39:42 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FUNCTION ft_tolower (recreate libc function)
/**
 * @brief Convert lowercase.
 * 
 * The original function is part of the <ctype.h> standard library.
 * If c is neither an unsigned char value nor EOF, the behavior of these
 *  functions is undefined.
 * 
 * @param c An int representing an ASCII letter (uppercase or lowercase).
 * @return The value of the converted letter.
 * @return c if the conversion was not possible.
 * 
 * @note No external dependencies allowed.
 */
//int	tolower(int c);
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
