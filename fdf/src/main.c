/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:48:26 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/08 17:06:46 by ruzhang          ###   ########.fr       */
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

	if (ac != 2)
		exit(EXIT_FAILURE);
	fdf = init_fdf(av[1]);
	fdf->map = get_map(av[1]);
	memset(fdf->img->pixels, 255, fdf->img->width * fdf->img->height * sizeof(int32_t));
	if (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0)
	ft_error();
	//mlx_loop_hook(fdf->mlx, ft_hook, fdf->mlx);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
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
