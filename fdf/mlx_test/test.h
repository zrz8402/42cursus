#ifndef TEST_H
# define TEST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "test.h"

void my_scrollhook(double xdelta, double ydelta, void* param);
void my_keyhook(mlx_key_data_t keydata, void* param);
void	set(mlx_t *mlx);

#endif