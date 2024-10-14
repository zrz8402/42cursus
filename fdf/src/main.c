/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:48:26 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/14 15:49:47 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

int32_t	main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;

	if (ac < 2)
		error("No arguement");
	if (ac > 2)
		error("Too many arguements");
	map = get_map(map, av[1]);
	fdf = init_fdf(map);
	draw(map, fdf);
	set_control(fdf);
	mlx_loop(fdf->mlx);
}
