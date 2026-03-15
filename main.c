#include "fdf.h"

void draw_line(t_data *data, int x1, int y1, int x2, int y2)
{
    float x_step = x2 - x1;
    float y_step = y2 - y1;
    int max = (abs((int)x_step) > abs((int)y_step)) ? abs((int)x_step) : abs((int)y_step);
    
    x_step /= max;
    y_step /= max;

    float x = x1;
    float y = y1;

    while ((int)(x - x2) || (int)(y - y2)) {
        if (x > 0 && y > 0 && x < WINDOW_WIDHT && y < WINDOW_HEIGHT) 
            my_mlx_pixel_put(data, (int)x, (int)y, 0x00FFFFFF);
        x += x_step;
        y += y_step;
    }
}


void	init_data(t_data *data)
{
	data->zoom = 70;
	data->offset_x = WINDOW_WIDHT / 2 - 200;
	data->offset_y = WINDOW_HEIGHT / 2 - 200;
	data->angle = 0.523599;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	init_data(&data);
	data.coordinates = parse_map(av[1], &data);
	if (!data.coordinates)
		return (1);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WINDOW_WIDHT, WINDOW_HEIGHT, "FdF");
	data.img = mlx_new_image(data.mlx, WINDOW_WIDHT, WINDOW_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, 
			&data.line_length, &data.endian);
	draw_map(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
    mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}