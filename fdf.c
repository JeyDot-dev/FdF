/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:02 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/07 11:53:49 by jsousa-a         ###   ########.fr       */
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
	pts.x = round(pts.x + cos(90) * pts.z);
	pts.y = round(pts.y + sin(90) * pts.z);
	pts.x2 = round(pts.x2 + cos(90) * pts.z2);
	pts.y2 = round(pts.y2 + sin(90) * pts.z2);
	//pts.x = round(pts.x * cos(120) + pts.x * cos(120 + 2) + pts.z * cos(120 - 2));
	//pts.y = round(pts.y * sin(120) + pts.x * sin(120 + 2) + pts.z * sin(120 - 2));
	//pts.x2 = round(pts.x2 * cos(120) + pts.x2 * cos(120 + 2) + pts.z2 * cos(120 - 2));
	//pts.y2 = round(pts.y2 * sin(120) + pts.x2 * sin(120 + 2) + pts.z2 * sin(120 - 2));
	return (pts);
}

t_coordinate base_pts(t_coordinate pts)
{
	int base_x = 1920 / 2;
	int base_y = 1080 / 2;
	int inc = 50;

	pts.x = base_x + inc * pts.x;
	pts.y = base_y + inc * pts.y;
	pts.z = inc * pts.z;
	pts.x2 = base_x + inc * pts.x2;
	pts.y2 = base_y + inc * pts.y2;
	pts.z2  = inc * pts.z2;
	return (pts);
}
t_coordinate base_pt1(int a, int b, int c)
{
	t_coordinate	pts;
	pts.x = a;
	pts.y = b;
	pts.z = c;
	return (pts);
}
t_coordinate base_pt2(t_coordinate pts, int a, int b, int c)
{
	pts.x2 = a;
	pts.y2 = b;
	pts.z2 = c;
	return (pts);
}

void ft_line_test(t_imgdata *img)
{
	t_coordinate	pts;
	pts = base_pt1(0, 0, 0);
	pts = base_pt2(pts, 1, 0, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 0, 0, 0));
	pts = base_pt1(0, 1, 0);
	pts = base_pt2(pts, 1, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 0, 0, 0));
	pts = base_pt1(0, 0, 0);
	pts = base_pt2(pts, 0, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(0, 255, 0, 0));
	pts = base_pt1(1, 0, 0);
	pts = base_pt2(pts, 1, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(0, 255, 0, 0));
	pts = base_pt1(0, 0, 0);
	pts = base_pt2(pts, 1, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 255, 0, 0));
	pts = base_pt1(1, 0, 0);
	pts = base_pt2(pts, 0, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 255, 0, 0));
	//--------------------
	pts = base_pt1(0, 0, 1);
	pts = base_pt2(pts, 1, 0, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 0, 0, 0));
	pts = base_pt1(0, 1, 1);
	pts = base_pt2(pts, 1, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 0, 0, 0));
	pts = base_pt1(0, 0, 1);
	pts = base_pt2(pts, 0, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(0, 255, 0, 0));
	pts = base_pt1(1, 0, 1);
	pts = base_pt2(pts, 1, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(0, 255, 0, 0));
	pts = base_pt1(0, 0, 1);
	pts = base_pt2(pts, 1, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 255, 0, 0));
	pts = base_pt1(1, 0, 1);
	pts = base_pt2(pts, 0, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 255, 0, 0));
	pts = base_pt1(0, 0, 0);
	pts = base_pt2(pts, 0, 0, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(0, 0, 255, 50));
	pts = base_pt1(0, 1, 0);
	pts = base_pt2(pts, 0, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(0, 0, 255, 50));
	pts = base_pt1(1, 0, 0);
	pts = base_pt2(pts, 1, 0, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(0, 0, 255, 50));
	pts = base_pt1(1, 1, 0);
	pts = base_pt2(pts, 1, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(0, 0, 255, 50));
}
/*void	ft_cube(t_imgdata img)
{
	t_coordinate	pts;
	pts = base_pt1(0, 0, 0);
	pts = base_pt2(pts, 1, 0, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(255, 0, 0, 0));
//----------------------------------
	pts = base_pt1(0, 0, 1);
	pts = base_pt2(pts, 1, 0, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(255, 255, 0, 0));
//----------------------------------
	pts = base_pt1(0, 0, 1);
	pts = base_pt2(pts, 0, 0, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(0, 255, 0, 0));
//----------------------------------
	pts = base_pt1(1, 0, 1);
	pts = base_pt2(pts, 1, 0, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(255, 0, 255, 0));
//----------------------------------
	pts = base_pt1(0, 0, 1);
	pts = base_pt2(pts, 0, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(0, 0, 255, 0));
//----------------------------------
	pts = base_pt1(1, 0, 1);
	pts = base_pt2(pts, 1, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(255, 255, 255, 0));
//----------------------------------
	pts = base_pt1(0, 0, 1);
	pts = base_pt2(pts, 0, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(0, 255, 255, 0));
//----------------------------------
	pts = base_pt1(1, 0, 0);
	pts = base_pt2(pts, 1, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(130, 130, 255, 0));
//----------------------------------
	pts = base_pt1(1, 1, 1);
	pts = base_pt2(pts, 1, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(70, 190, 255, 0));
//----------------------------------
	pts = base_pt1(1, 1, 0);
	pts = base_pt2(pts, 0, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(70, 255, 120, 0));
//----------------------------------
	pts = base_pt1(0, 1, 0);
	pts = base_pt2(pts, 0, 0, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	put_line(&img, pts, rgbo_color(70, 255, 255, 0));
}
*/
int	main(void)
{
	void			*mlx;
	void			*mlx_win;
	t_imgdata		img;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "test window");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	ft_line_test(&img);
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
