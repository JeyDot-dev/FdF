/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:02 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/03 16:36:46 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
//t_imgdata .img .addr .bpp .line_len .endian
//t_coordinate .x .x2 .y .y2
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

int	main(void)
{
	void			*mlx;
	void			*mlx_win;
	t_imgdata		img;
	t_coordinate	pts;
							pts.x = 300;
							pts.y = 300;
							pts.x2 = 30;
							pts.y2 = 30;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "test window");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	put_line(&img, pts, 0x00FF00FF);
							pts.x = 30;
							pts.y = 300;
							pts.x2 = 300;
							pts.y2 = 30;
	put_line(&img, pts, 0x00FF00FF);
							pts.x = 166;
							pts.y = 300;
							pts.x2 = 166;
							pts.y2 = 30;
	put_line(&img, pts, 0x00FF00FF);
							pts.x = 30;
							pts.y = 166;
							pts.x2 = 300;
							pts.y2 = 166;
	put_line(&img, pts, 0x00FF00FF);
							pts.x = 99;
							pts.y = 300;
							pts.x2 = 231;
							pts.y2 = 30;
	put_line(&img, pts, 0x00FF00FF);
							pts.x = 99;
							pts.y = 30;
							pts.x2 = 231;
							pts.y2 = 300;
	put_line(&img, pts, 0x00FF00FF);
							pts.x = 30;
							pts.y = 99;
							pts.x2 = 300;
							pts.y2 = 231;
	put_line(&img, pts, 0x00FF00FF);
							pts.x = 30;
							pts.y = 231;
							pts.x2 = 300;
							pts.y2 = 99;
	put_line(&img, pts, 0x00FF00FF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
