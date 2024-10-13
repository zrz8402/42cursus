/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:48:26 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/13 17:42:59 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

int32_t	main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;

	if (ac != 2)
		exit(EXIT_FAILURE);
	map = get_map(av[1]);
	//printf("(%d %d)", map->width, map->height);
	fdf = init_fdf(map);
	draw(map, fdf);
	//set_control(fdf);
	mlx_loop(fdf->mlx);
}

/*
int32_t	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		exit(EXIT_FAILURE);
	fdf = init_fdf(av[1]);
	map = get_map(av[1]);
	printf("map height: %d, map width: %d\n", map->height, map->width);
	int i = 0;	
	while (i < map->height)
	{
		int j = 0;
		while (j < map->width)
		{
			printf("%d,%d ", map->num_arr[i][j], map->color_arr[i][j]);
			//printf("%d ", map->num_arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free(fdf);
}
*/
