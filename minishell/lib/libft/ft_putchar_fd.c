/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:37:17 by kmartin           #+#    #+#             */
/*   Updated: 2024/02/26 21:39:42 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// FUNCTION ft_putchar_fd (novel function)
/**
 * @brief Outputs a character to a specified file descriptor.
 * 
 * Outputs the character ‘c’ to the given file descriptor.
 * 
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 * 
 * @note Depends on write() from <unistd.h>.
 */
//void	ft_putchar_fd(char c, int fd);
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
