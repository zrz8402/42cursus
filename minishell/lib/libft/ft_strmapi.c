/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin <kmartin@student.42bangkok.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:26:36 by kmartin           #+#    #+#             */
/*   Updated: 2024/02/29 00:51:36 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// FUNCTION ft_strmapi (novel function)
/**
 * @brief Applies another function to each character of a string,  returning a
 *  new string.
 * 
 * Applies the function ‘f’ to each character of the string ‘s’, and passing its
 *  index as first argument to create a new string with malloc() resulting from
 *  successive applications of ‘f’.
 * 
 * @param s The string on which to iterate.
 * f The function to apply to each character.
 * @return The string created from the successive applications of ‘f’.
 * @return NULL if the allocation fails.
 * 
 * @note Depends on malloc() from <stdlib.h>.
 */
//char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	int				strlen;
	unsigned int	i;

	strlen = ft_strlen(s);
	newstr = (char *)malloc(sizeof(char) * (strlen + 1));
	if (newstr == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
