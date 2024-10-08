/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:11:42 by ruzhang           #+#    #+#             */
/*   Updated: 2024/09/29 16:49:52 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "libft.h"
# include "MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef	struct s_map
{
	int	width;
	int	height;
	int	**num_arr;
	int	**color_arr;
	int	z_min;
	int	z_max;
}	t_map;

typedef	struct fdf
{
	mlx_t	*mlx;
}	t_fdf;


void	init_map(t_map *map, char *fname);
int	error(char *message);
#endif