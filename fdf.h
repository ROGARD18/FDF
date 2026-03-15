#ifndef FDF_H
# define FDF_H

/* Paramètres de fenêtre */
# define WINDOW_WIDHT 3940
# define WINDOW_HEIGHT 2160

/* Bibliothèques standards */
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

/* Structures */
typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     *coordinates;
    int     width_map;
    int     height_map;
    int     zoom;
    int     offset_x;
    int     offset_y;
    double  angle;
}           t_data;

typedef struct s_point
{
    int     x;
    int     y;
    int     z;
}           t_point;

void        get_dimensions(char *file, t_data *data);
int         *parse_map(char *file, t_data *data);
int         count_words(char const *s, char c);
char        **ft_split(char const *s, char c);
int         ft_atoi(const char *str);
char        *get_next_line(int fd);

void        my_mlx_pixel_put(t_data *data, int x, int y, int color);
void        isometric(int *x, int *y, int z, double angle);
void        bresenham(t_data *data, t_point p1, t_point p2);
int         create_trgb(int t, int r, int g, int b);
int         get_color(int start_color, int end_color, double percent);
void        draw_map(t_data *data);
int         key_hook(int keycode, t_data *data);
int         mouse_hook(int button, int x, int y, t_data *data);

void	render_map(t_data *data);


#endif