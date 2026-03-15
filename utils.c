#include "fdf.h"

void	get_dimensions(char *file, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	if (!line)
		exit(1);
	data->width_map = count_words(line, ' ');
	data->height_map = 0;
	while (line)
	{
		data->height_map++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDHT || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

void	render_map(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	
	data->img = mlx_new_image(data->mlx, WINDOW_WIDHT, WINDOW_HEIGHT);
	if (!data->img)
		exit(1);
		
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, 
			&data->line_length, &data->endian);
	
	draw_map(data);
	
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}