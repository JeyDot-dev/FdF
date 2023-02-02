/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:02 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/02 16:05:38 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
//t_imgdata .img .addr .bpp .line_len .endian
//t_coordinate .x .x2 .y .y2
int rgbo_color(int r, int g, int b, int o)
{
    int color = 0;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
    color |= b;
    color |= g << 8;
    color |= r << 16;
	color |= o << 24;
    return (color);
}

void	my_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*colordst;

	colordst = img->addr + (img->line_len * y + (img->bpp / 8) * x);
	*(unsigned int*)colordst = color;
}
unsigned int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
void	put_line(void *mlx_win, void *mlx, t_imgdata *img, t_coordinate pts)
{
	int dy;
	int e;
	int dx;
	int inc[2];

	dy = ft_abs((pts.y2 - pts.y) * 2);
	e = ft_abs(pts.x2 - pts.x);
	dx = e * 2;
	inc[0] = 1;
	inc[1] = 1;
	if (pts.y2 < pts.y)
		inc[1] = -1;
	while (pts.x <= pts.x2)
	{
		my_pixel_put(img, pts.x, pts.y, rgbo_color(255, 0, 150, 0));
		pts.x++;
		e -= dy;
		if (e <= 0)
		{
			pts.y += inc[1];
			e += dx;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}
int	main(void)
{
	void			*mlx;
	void			*mlx_win;
	t_imgdata		img;
	t_coordinate	pts;
							pts.x = 54;
							pts.x2 = 900;
							pts.y = 900;
							pts.y2 = 42;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "test window");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	put_line(mlx_win, mlx, &img, pts);
	mlx_loop(mlx);
}
