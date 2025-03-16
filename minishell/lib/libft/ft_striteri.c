/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:38:08 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 13:35:05 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// FUNCTION ft_striteri (novel function)
/**
 * @brief Applies another function to each character of a string, modifying them
 *  in place.
 * 
 * Applies the function ‘f’ on each character of the string passed as argument,
 *  passing its index as first argument. Each character is passed by address to
 *  ‘f’ to be modified if necessary.
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return None.
 * 
 * @note No external dependencies allowed.
 */
//void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}
