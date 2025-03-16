/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmartin < kmartin@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:37:35 by kmartin           #+#    #+#             */
/*   Updated: 2024/03/11 13:45:02 by kmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

static int	count_integer_chars(int n);
static void	output_indexed_digits(int n, int num_char, int fd);

// FUNCTION ft_putnbr_fd (novel function)
/**
 * @brief Outputs an integer to a specified file descriptor.
 * 
 * Outputs the integer ‘n’ to the given file descriptor.
 * 
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * @return None.
 * 
 * @note Depends on write() from <unistd.h>.
 */
//void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_fd(int n, int fd)
{
	int	rem;
	int	num_char;

	num_char = count_integer_chars(n);
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	rem = n;
	if (rem < 0)
	{
		rem = rem * -1;
		write(fd, "-", 1);
	}
	output_indexed_digits(rem, num_char, fd);
}

// Helper function - count characters to output (not including '-')
static int	count_integer_chars(int n)
{
	int	rem;
	int	c;

	rem = n;
	c = 0;
	if (rem < 0)
		rem = rem * -1;
	while (rem >= 10)
	{
		rem = rem / 10;
		c++;
	}
	c++;
	return (c);
}

// Helper function - output digit at index position in +ve integer 
static void	output_indexed_digits(int n, int num_char, int fd)
{
	char	c;
	int		rem;
	int		div;
	int		i;

	i = 0;
	while (i < num_char)
	{
		rem = n;
		div = 0;
		while (div < num_char - i - 1)
		{
			rem = rem / 10;
			div++;
		}
		c = (rem % 10) + '0';
		write(fd, &c, 1);
		i++;
	}
}
