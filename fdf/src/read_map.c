#include "fdf.h"
#include "libft.h"

int	get_width(char *line)
{
	int	width;

	width = 0;
	while (*line)
	{
		if (*line != ' ' && (!(*line + 1) || *(line + 1) == ' '))
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
		error("Empty map"); //is a empty map
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

void	fill_map(t_map *map, char *fname)
{
	int		fd;
	char	*line;
	char	**strs;
	int		i;
	int		j;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		error("Error opening file");
	map->num_arr = malloc(sizeof(int *) * map->height);
	map->color_arr = malloc(sizeof(int *) * map->height);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		j = 0;
		strs = ft_split(line, ' ');
		while (j < map->width)
		{
			map->num_arr[i][j] = ft_atoi(strs[j]);
			
		}
		line = get_next_line(fd);
	}
	close(fd);
}

void	init_map(t_map *map, char *fname)
{
	get_dimension(map, fname);
}