/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:11:42 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/16 15:09:53 by ruzhang          ###   ########.fr       */
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

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WIDTH 2056
# define HEIGHT 2056

typedef enum e_prjection
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
	int				width;
	int				height;
	int				**num_arr;
	int				**color_arr;
	int				z_min;
	int				z_max;
	unsigned int	z_range;
}	t_map;

typedef struct s_camera
{
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	t_projection	projection;
	int				x_offset;
	int				y_offset;
	float			z_divisor;
}	t_camera;

typedef struct fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	int			steep;
	t_camera	*camera;
}	t_fdf;

//main.c 
int32_t		main(int ac, char **av);

// map.c
// undefined behavior in get_next_line when file isn't read unitil the end
t_map		*get_map(char *fname);

//utils.c
void		error(char *message);
int			ft_atoi_hex(char *s);
void		free_map(t_map *map);
void		free_arr(char **s);

// init.c
t_map		*init_map(void);
t_camera	*init_camera(t_fdf *fdf);
void		init_fdf(t_map *map, t_fdf *fdf);
void		free_fdf(t_fdf *fdf);

//draw.c
void		draw(t_map *map, t_fdf *fdf);
int			default_color(t_map *map, int altitude);
t_point		point(t_map *map, int x, int y);

// project.c
void		rotate_x(int *y, int *z, double angle);
void		rotate_y(int *x, int *z, double angle);
void		rotate_z(int *x, int *y, double angle);
void		iso(int *x, int *y, int z);
t_point		project(t_fdf *fdf, t_point point);

// line.c
int			rgb(int first, int second, float percent, float intensity);
uint32_t	get_c(int x, t_point sp, t_point ep, float intensity);
void		plot(t_fdf *fdf, t_point sp, t_point ep, float gradient);
void		draw_line(t_fdf *fdf, t_point sp, t_point ep);

// line_utils.c
void		swap(int *a, int *b);
int			ipt(float n);
float		fpt(float n);
float		rfpt(float n);

// hooks.c
void		key_press(mlx_key_data_t keycode, void *param);
void		mouse_press(mouse_key_t button, void *param);
void		scroll(double xdelta, double ydelta, void *param);
void		hook_control(t_fdf *fdf);

// actions.c
void		zoom(int key, t_fdf *fdf);
void		move(int key, t_fdf *fdf);
void		rotate(int key, t_fdf *fdf);
void		flatten(int key, t_fdf *fdf);
void		change_projection(int key, t_fdf *fdf);

// instruction.c
void		instruction(t_fdf *fdf);

#endif