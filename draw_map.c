#include "fdf.h"

// Fonction interne pour isoler le calcul d'un point unique
static t_point project_point(int x, int y, t_data *data)
{
    t_point p;
    int     z;

    z = data->coordinates[(y * data->width_map) + x];
    
    // On scale d'abord par le zoom
    p.x = x * data->zoom;
    p.y = y * data->zoom;
    p.z = z;

    // On passe par isometric (qui devrait idéalement utiliser des doubles en interne)
    // Ici, on multiplie aussi le Z par le zoom pour garder les proportions
    isometric(&p.x, &p.y, (z * data->zoom) / 10, data->angle);

    // On applique le décalage pour le centrage
    p.x += data->offset_x;
    p.y += data->offset_y;
    
    return (p);
}

void draw_map(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->height_map)
    {
        x = 0;
        while (x < data->width_map)
        {
            if (x < data->width_map - 1)
                bresenham(data, project_point(x, y, data), project_point(x + 1, y, data));
            if (y < data->height_map - 1)
                bresenham(data, project_point(x, y, data), project_point(x, y + 1, data));
            x++;
        }
        y++;
    }
}