/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:11:42 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/08 17:12:37 by ruzhang          ###   ########.fr       */
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

# define WIDTH 512
# define HEIGHT 512

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int	**num_arr;
	int	**color_arr;
	int	z_min;
	int	z_max;
}	t_map;

typedef struct fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
}	t_fdf;

t_fdf	*init_fdf(char *fname);
t_map	*get_map(char *fname);

//utils.c
int		ft_atoi_hex(char *s);
int		error(char *message);
#endif