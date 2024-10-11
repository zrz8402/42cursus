/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:48:26 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/11 13:49:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>
void ft_error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;

	if (ac != 2)
		exit(EXIT_FAILURE);
	map = get_map(av[1]);
	fdf = init_fdf(map);
	draw(fdf->map, fdf);
	mlx_loop(fdf->mlx);
}

/*
int32_t	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		exit(EXIT_FAILURE);
	fdf = init_fdf(av[1]);
	fdf->map = get_map(av[1]);
	printf("map height: %d, map width: %d\n", fdf->map->height, fdf->map->width);
	int i = 0;	
	while (i < fdf->map->height)
	{
		int j = 0;
		while (j < fdf->map->width)
		{
			printf("%d,%d ", fdf->map->num_arr[i][j], fdf->map->color_arr[i][j]);
			//printf("%d ", fdf->map->num_arr[i][j]);
			j++;
		}
		free(fdf->map->color_arr[i]);
		free(fdf->map->num_arr[i]);
		printf("\n");
		i++;
	}
	free(fdf->map->color_arr);
	free(fdf->map->num_arr);
	free(fdf->map);
	free(fdf);
}
*/
