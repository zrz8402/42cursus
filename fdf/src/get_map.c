/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:47:49 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/13 16:55:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_width(char *line)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n'
			&& (i == 0 || (line[i - 1] == ' ')))
			width++;
		i++;
	}
	return (width);
}

static void	get_dimension(t_map *map, char *fname)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (free_map(map), error("Error opening file"));
	line = get_next_line(fd);
	if (!line)
		return (free_map(map), error("Empty map"));
	map->width = get_width(line);
	while (line)
	{
		len = get_width(line);
		free(line);
		if (len != map->width)
			return (free_map(map), error("Wrong map format"));
		map->height++;
		line = get_next_line(fd);
	}
	close(fd);
}

static void	get_num_col(t_map *map, char *line, int i)
{
	char	**strs;
	char	**num_col;
	int		j;

	j = 0;
	strs = ft_split(line, ' ');
	while (j < map->width)
	{
		num_col = ft_split(strs[j], ',');
		map->num_arr[i][j] = ft_atoi(num_col[0]);
		if (num_col[1])
			map->color_arr[i][j] = ft_atoi_hex(num_col[1]);
		else
			map->color_arr[i][j] = 0;
		j++;
		free_arr(num_col);
	}
	free_arr(strs);
}

static void	fill_map(t_map *map, char *fname)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (free_map(map), error("Error opening file"));
	map->num_arr = malloc(sizeof(int *) * map->height);
	map->color_arr = malloc(sizeof(int *) * map->height);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map->num_arr[i] = malloc(sizeof(int) * map->width);
		map->color_arr[i] = malloc(sizeof(int) * map->width);
		get_num_col(map, line, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

t_map	*get_map(char *fname)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		error("Error initiating map.");
	ft_memset(map, 0, sizeof(t_map));
	get_dimension(map, fname);
	fill_map(map, fname);
	return (map);
}
