#include "fdf.h"
#include <stdlib.h>

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307){
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
    }

	if (keycode == 65364)
		data->angle += 0.05;
	else if (keycode == 65362)  
		data->angle -= 0.05;
	else if (keycode == 65363)
		data->offset_x += 10;
	else if (keycode == 65361)
		data->offset_x -= 10;
	
	render_map(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	
	if (button == 4)
		data->zoom += 2;
	else if (button == 5)
	{
		if (data->zoom > 2)
			data->zoom -= 2;
	}
	else
		return (0);

	render_map(data);
	return (0);
}
