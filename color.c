// int	get_t(int trgb)
// {
// 	return ((trgb >> 24) & 0xFF);
// }

// int	get_r(int trgb)
// {
// 	return ((trgb >> 16) & 0xFF);
// }

// int	get_g(int trgb)
// {
// 	return ((trgb >> 8) & 0xFF);
// }

// int	get_b(int trgb)
// {
// 	return (trgb & 0xFF);
// }

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }
int get_color(int start_color, int end_color, double percent)
{
    int red;
    int green;
    int blue;
    int start_r = (start_color >> 16) & 0xFF;
    int end_r   = (end_color >> 16) & 0xFF;
    int start_g = (start_color >> 8) & 0xFF;
    int end_g   = (end_color >> 8) & 0xFF;
    int start_b = start_color & 0xFF;
    int end_b   = end_color & 0xFF;

    red   = start_r + (end_r - start_r) * percent;
    green = start_g + (end_g - start_g) * percent;
    blue  = start_b + (end_b - start_b) * percent;

    return ((red << 16) | (green << 8) | blue);
}