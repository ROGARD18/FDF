#include "fdf.h"

static void	fill_coordinates(int *coordinates, char *line, int y, t_data *data)
{
	char	**split;
	int		x;

	split = ft_split(line, ' ');
	x = 0;
	while (split[x] && x < data->width_map)
	{
		coordinates[y * data->width_map + x] = ft_atoi(split[x]);
		free(split[x]);
		x++;
	}
	free(split);
}

int	*parse_map(char *file, t_data *data)
{
	int		fd;
	int		*coordinates;
	char	*line;
	int		y;

	get_dimensions(file, data);
	coordinates = malloc(sizeof(int) * (data->width_map * data->height_map));
	if (!coordinates)
		return (NULL);
	fd = open(file, O_RDONLY);
	y = 0;
	while (y < data->height_map)
	{
		line = get_next_line(fd);
		fill_coordinates(coordinates, line, y, data);
		free(line);
		y++;
	}
	close(fd);
	return (coordinates);
}