/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:11:42 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/13 18:24:03 by ruzhang          ###   ########.fr       */
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

# define FT_INT_MAX ((int)(~0U >> 1))
# define FT_INT_MIN ((int)(~FT_INT_MAX))
// close window
# define KEY_ESCAPE 256

// move map
# define ARROW_RIGHT 262
# define ARROW_LEFT 263
# define ARROW_DOWN 264
# define ARROW_UP 265

// change projection: I-isometric, P-parallel
# define KEY_I 73
# define KEY_P 80

// zoom
# define KEY_MINUS 45
# define KEY_PLUS 62
# define KP_MINUS 333
# define KP_PLUS 334

// flatten
# define KEY_LESS 44
# define KEY_MORE 46

// rotate
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define KEY_5 53
# define KEY_6 54
# define KP_1 321
# define KP_2 322
# define KP_3 323
# define KP_4 324
# define KP_5 325
# define KP_6 326


# define MOUSE_SCROLL_UP 256
# define MOUSE_SCROLL_DOWN 256

typedef enum
{
	ISO,
	PARALLEL,
}	t_projection;

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
	int	z_min;
	int	z_max;
	int	z_range;
}	t_map;

typedef struct s_camera
{
	int		zoom;
	double	alpha; //rotate around x
	double	belta; //rotate around y
	double	gamma; //rotate around z
	t_projection	projection;
}	t_camera;

typedef struct s_mouse
{
	int	x;
	int	y;
	int	is_pressed;
}	t_mouse;

typedef struct fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	int			steep;
	t_camera	*camera;
	t_mouse		*mouse;
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
t_map	*get_map(t_map *map,char *fname);

//draw.c
void	draw(t_map *map, t_fdf *fdf);

//utils.c
t_map	*init_map(void);
t_fdf	*init_fdf(t_map *map);
void	error(char *message);
int		ft_atoi_hex(char *s);
void	free_map(t_map *map);
void	free_arr(char **s);

// line.c
int		rgb(int first, int second, float percent, float intensity);
uint32_t		get_c(int x, t_point sp, t_point ep, float intensity);
void	put_pixel(t_fdf *fdf, int x, int y, int color);
void	plot(t_fdf *fdf, t_point sp, t_point ep, float gradient);
void	draw_line(t_fdf *fdf, t_point sp, t_point ep);

// line_utils.c
void	swap(int *a, int *b);
int		ipt(float n);
float	fpt(float n);
float	rfpt(float n);


void	set_control(t_fdf *fdf);

#endif