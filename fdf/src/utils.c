/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:48:32 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/08 17:11:50 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(char *fname)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init(WIDTH, HEIGHT, fname, true);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->map = NULL;
	printf("%s\n", fname);
	return (fdf);
}

int	error(char *message)
{
	printf("%s\n", message);
	exit(1);
}
int	ft_atoi_hex(char *s)
{
	int	result;
	int	n;

	result = 0;
	if (!ft_strncmp(s, "0x", 2))
		s += 2;
	else
		return (result);
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			n = *s - '0';
		else if (*s >= 'a' && *s <= 'z')
			n = *s + 10 - 'a';
		else if (*s >= 'A' && *s <= 'Z')
			n = *s + 10 - 'A';
		else
			break ;
		result = result * 16 + n;
		s++;
	}
	return (result);
}
