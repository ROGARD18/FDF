#include <math.h>
#include "fdf.h"

int ft_abs(int nb)
{
    if (nb < 0)
        return (nb * -1);
    return (nb);
}

void bresenham(t_data *data, t_point p1, t_point p2)
{
    int diff_x = ft_abs(p1.x - p2.x);
    int diff_y = ft_abs(p1.y - p2.y);
    int sens_x = (p1.x < p2.x) ? 1 : -1;
    int sens_y = (p1.y < p2.y) ? 1 : -1;
    int err = diff_x - diff_y;
    int e2;

    int color_start;
    int color_end;
    int current_color;

    color_start = (p1.z != 0) ? 0xEE82EE : 0xFFFFFF; 
    color_end   = (p2.z != 0) ? 0xEE82EE : 0xFFFFFF;
    // ----------------------------------

    int len_max = (diff_x > diff_y) ? diff_x : diff_y;
    int i = 0;

    while (1)
    {
        double percent = (len_max > 0) ? ((double)i / (double)len_max) : 1.0;
        if (p1.z != 0 || p2.z != 0)
        {
            color_start = 0x00EE82EE;
            color_end = 0x00FFA500;
        }
        if (p1.z != 0 && p2.z != 0)
        {
            color_start = 0x00EE82EE;
            color_end = 0x00EE82EE;
        }
        current_color = get_color(color_start, color_end, percent);
        if (p1.x >= 0 && p1.x < WINDOW_WIDHT && p1.y >= 0 && p1.y < WINDOW_HEIGHT)
            my_mlx_pixel_put(data, p1.x, p1.y, current_color);

        if (p1.x == p2.x && p1.y == p2.y)
            break ;
        
        e2 = 2 * err;
        if (e2 > -diff_y)
        {
            err -= diff_y;
            p1.x += sens_x;
        }
        if (e2 < diff_x)
        {
            err += diff_x;
            p1.y += sens_y;
        }
        i++;
    }
}

void isometric(int *x, int *y, int z, double angle)
{
    int previous_x = *x;
    int previous_y = *y;

    *x = (previous_x - previous_y) * cos(angle) ;
    *y = (previous_x + previous_y) * sin(angle) - z;
}
