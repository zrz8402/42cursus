#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		exit(EXIT_FAILURE);
	map = malloc(sizeof(t_map)); 
 	ft_memset(map, 0, sizeof(t_map));
 	printf("%s\n", av[1]);
 	init_map(map, av[1]);
	free(map);
}