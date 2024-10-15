
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#define WIDTH 720
#define HEIGHT 480
#include "test.h"


int32_t	main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);
	set(mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

//cc key.c ../lib/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -o test