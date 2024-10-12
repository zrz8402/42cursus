/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:11:42 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/12 18:22:48 by ruzhang          ###   ########.fr       */
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

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	c;
	int	reverse;
}	t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int	**num_arr;
	int	**color_arr;
}	t_map;

typedef struct fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	int			steep;
}	t_fdf;

//main.c 
int32_t	main(int ac, char **av);

// get_map.c
// undefined behavior from get_next_line
// leaks when the file isn't fully read
static int	get_width(char *line);
static void	get_dimension(t_map *map, char *fname);
static void	get_num_col(t_map *map, char *line, int i);
static void	fill_map(t_map *map, char *fname);
t_map	*get_map(char *fname);

//draw.c
void	draw(t_map *map, t_fdf *fdf);

//utils.c
t_fdf	*init_fdf(t_map *map);
void	error(char *message);
int		ft_atoi_hex(char *s);
void	free_map(t_map *map);
void	free_arr(char **s);

// line.c
int		rgb(int first, int second, float percent, float intensity);
int		get_c(int x, t_point sp, t_point ep, float intensity);
void	put_pixel(t_fdf *fdf, int x, int y, int color);
void	plot(t_fdf *fdf, t_point sp, t_point ep, float gradient);
void	draw_line(t_fdf *fdf, t_point sp, t_point ep);

// line_utils.c
void	swap(int *a, int *b);
int		ipt(float n);
float	fpt(float n);
float	rfpt(float n);

#endif