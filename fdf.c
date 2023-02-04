/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:02 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/04 15:31:03 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
//t_imgdata .img .addr .bpp .line_len .endian
//t_coordinate .x .x2 .y .y2 .z .z2
int	rgbo_color(int r, int g, int b, int o)
{
	int	color;

	color = 0;
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
t_coordinate to_isometric(t_coordinate pts)
{
	pts.x = x * cos(120) + x * cos(120 + 2) + z * cos(120 - 2);
	pts.y = y * sin(120) + x * sin(120 + 2) + z * sin(120 - 2);
	pts.x2 = x2 * cos(120) + x2 * cos(120 + 2) + z2 * cos(120 - 2);
	pts.y2 = y2 * sin(120) + x2 * sin(120 + 2) + z2 * sin(120 - 2);
	return (pts);
}
void	ft_cube(t_imgdata img)
{
	t_coordinate	pts;
	int base_x = 1920 / 2;
	int base_y = 1080 / 2;
	int inc = 15;
	int x, y, z, x2, y2, z2;

	pts.x = base_x + inc * 0;
	pts.y = base_y + inc * 0;
	pts.z = inc * 0;
	pts.x2 = base_x + inc * 1;
	pts.y2 = bas_y + inc * 0;
	pts.z2  = inc * 0;
	pts = to_isometric(pts);
	put_line(img, pts, 0x00FFFFFF);
}
int	main(void)
{
	void			*mlx;
	void			*mlx_win;
	t_imgdata		img;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "test window");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
							ft_cube(img);
//							pts.x = ft_abs((x - y) * cos(0.523599), '+');
//							pts.y = ft_abs((x + y - z) * sin(0.523599), '+');
//							pts.x2 = ft_abs((x2 - y2) * cos(0.523599), '+');
//							pts.y2 = ft_abs((x2 + y2 - z2) * sin(0.523599), '+');
//							x = 250;
//							y = 250;
//							z = 50;
//							x2 = 250;
//							y2 = 300;
//							z2 = 50;
//							pts.x = ft_abs(nearbyint((x - z) / sqrt(2)), '+');
//							pts.y = ft_abs(nearbyint((x + y + y + z) / sqrt(6)), '+');
//							pts.x2 = ft_abs(nearbyint((x2 - z2) / sqrt(2)), '+');
//							pts.y2 = ft_abs(nearbyint((x2 + y2 + y2 + z) / sqrt(6)), '+');
//	put_line(&img, pts, 0x00FFFFFF);
//							x = 250;
//							y = 250;
//							z = 0;
//							x2 = 250;
//							y2 = 250;
//							z2 = 50;
//							pts.x = ft_abs(nearbyint((x - z) / sqrt(2)), '+');
//							pts.y = ft_abs(nearbyint((x + y + y + z) / sqrt(6)), '+');
//							pts.x2 = ft_abs(nearbyint((x2 - z2) / sqrt(2)), '+');
//							pts.y2 = ft_abs(nearbyint((x2 + y2 + y2 + z) / sqrt(6)), '+');
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
