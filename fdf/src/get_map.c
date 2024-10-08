/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:47:49 by ruzhang           #+#    #+#             */
/*   Updated: 2024/10/08 16:21:26 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *line)
{
	int	width;

	width = 0;
	while (*line)
	{
		if (*line != ' ' && (!*(line + 1) || *(line + 1) == ' '))
			width++;
		line++;
	}
	return (width);
}

void	get_dimension(t_map *map, char *fname)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		error("Error opening file");
	line = get_next_line(fd);
	if (!line)
		error("Empty map");
	map->width = get_width(line);
	while (line)
	{
		len = get_width(line);
		free(line);
		if (len != map->width)
			error("Wrong map format");
		map->height++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_num_col(t_map *map, char *line, int i)
{
	char	**strs;
	int		j;

	j = 0;
	strs = ft_split(line, ' ');
	while (j < map->width)
	{
		map->num_arr[i][j] = ft_atoi(strs[j]);
		free(strs[j]);
		while (*strs[j] && *strs[j] != ',')
			strs[j]++;
		if (!*strs[j])
			map->color_arr[i][j] = 0;
		else
		{
			strs[j]++;
			map->color_arr[i][j] = ft_atoi_hex(strs[j]);
		}
		j++;
	}
	free(strs);
}

void	fill_map(t_map *map, char *fname)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		error("Error opening file");
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
	ft_memset(map, 0, sizeof(t_map));
	get_dimension(map, fname);
	fill_map(map, fname);
	return (map);
}
