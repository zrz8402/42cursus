#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define WIDTH 800
#define HEIGHT 600

typedef struct s_data {
    mlx_t *mlx_ptr;            // MLX context
    mlx_image_t *img_ptr;     // Image structure for pixel data
} t_data;

// Set pixel with given intensity
void plot(t_data *data, int x, int y, float intensity) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        int color = (int)(255 * intensity);
        int pixel_index = (x + y * data->img_ptr->width) * 4;  // RGBA
        data->img_ptr->pixels[pixel_index] = color;          // Blue
        data->img_ptr->pixels[pixel_index + 1] = color;      // Green
        data->img_ptr->pixels[pixel_index + 2] = color;      // Red
        data->img_ptr->pixels[pixel_index + 3] = 255;        // Alpha (opaque)
    }
}

// Wu's line algorithm implementation
void wuLine(t_data *data, int x0, int y0, int x1, int y1) {
    float slope = (float)(y1 - y0) / (x1 - x0);
    float x = x0;
    float y = y0;

    if (abs(x1 - x0) > abs(y1 - y0)) {
        if (x0 > x1) {
            int tmp_x = x0, tmp_y = y0;
            x0 = x1; y0 = y1;
            x1 = tmp_x; y1 = tmp_y;
        }
        for (x = x0; x <= x1; x++) {
            int y_int = (int)y;
            float intensity = 1.0 - (y - y_int);
            plot(data, (int)x, y_int, intensity);
            plot(data, (int)x, y_int + 1, 1.0 - intensity);
            y += slope;
        }
    } else {
        if (y0 > y1) {
            int tmp_x = x0, tmp_y = y0;
            x0 = x1; y0 = y1;
            x1 = tmp_x; y1 = tmp_y;
        }
        for (y = y0; y <= y1; y++) {
            int x_int = (int)x;
            float intensity = 1.0 - (x - x_int);
            plot(data, x_int, (int)y, intensity);
            plot(data, x_int + 1, (int)y, 1.0 - intensity);
            x += 1.0 / slope;
        }
    }
}

// Handle key press events
void close_window(mlx_key_data_t keydata, void* param) {
    t_data *data = (t_data *)param; // Cast the param back to t_data*
    if (keydata.key == 256) { // ESC key
        mlx_close_window(data->mlx_ptr);
    }
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	// Simple up or down detection.
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
	
	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

void	set(t_data *data)
{
	mlx_scroll_hook(data->mlx_ptr, &my_scrollhook, NULL);
	mlx_key_hook(data->mlx_ptr, &my_keyhook, NULL);
	//mlx_key_hook(data->mlx_ptr, &close_window, &data);
}

int main() {
    t_data data;

    // Initialize MLX
    data.mlx_ptr = mlx_init(WIDTH, HEIGHT, "Wu's Line Algorithm", true);
    if (!data.mlx_ptr) {
        fprintf(stderr, "Failed to initialize MLX\n");
        return EXIT_FAILURE;
    }

    // Create a new image
    data.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
    if (!data.img_ptr) {
        fprintf(stderr, "Failed to create image\n");
        mlx_terminate(data.mlx_ptr);
        return EXIT_FAILURE;
    }

    // Clear the image with black color
    memset(data.img_ptr->pixels, 0, WIDTH * HEIGHT * 4); // 4 bytes per pixel (RGBA)

    // Draw Wu's line from (50, 50) to (400, 200)
    wuLine(&data, 50, 50, 400, 200);

    // Display the image in the window
    if (mlx_image_to_window(data.mlx_ptr, data.img_ptr, 0, 0) < 0) {
        fprintf(stderr, "Failed to display image\n");
        mlx_delete_image(data.mlx_ptr, data.img_ptr);
        mlx_terminate(data.mlx_ptr);
        return EXIT_FAILURE;
    }

    // Set the key press handler
    //mlx_key_hook(data.mlx_ptr, close_window, &data); // Use the updated close_window function

	set(&data);
    // Start the event loop
    mlx_loop(data.mlx_ptr);

    // Cleanup (unreachable in this example due to mlx_loop)
    mlx_delete_image(data.mlx_ptr, data.img_ptr);
    mlx_terminate(data.mlx_ptr);
    return 0;
}
// cc test.c ./lib/MLX42/build/libmlx42.a -o test -lglfw -framework Cocoa -framework OpenGL -framework IOKit

//cc -fsanitize=address test.c ../lib/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -o test