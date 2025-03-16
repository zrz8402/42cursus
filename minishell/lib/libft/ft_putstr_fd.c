/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:37:43 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/01 16:35:12 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stddef.h>

// FUNCTION ft_putstr_fd (novel function)
/**
 * @brief Outputs a string to a specified file descriptor.
 * 
 * Outputs the string ‘s’ to the given file descriptor.
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 * 
 * @note Depends on write() from <unistd.h>.
 */
//void	ft_putstr_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	strlen;

	strlen = ft_strlen(s);
	i = 0;
	while (i < strlen)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
