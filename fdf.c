/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:02 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/14 22:34:12 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
//t_imgdata .img .addr .bpp .line_len .endian
//t_line_coordinates .x .x2 .y .y2 .z .z2




int	main(int ac, char **av)
{
	void			*mlx;
	void			*mlx_win;
	t_imgdata		img;
	t_pts_coordinates *pts;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "test window");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	int	fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	pts = map_to_pts(fd);
	link_pts(pts);
	scale_pts(pts);
	origin_pts(pts);
	altitude_color(pts);
	to_isometric(pts);
	draw_map(pts, &img);
//	while(pts)
//	{
//		printf("--x = %i, y = %i, z = %i\n", pts->x, pts->y, pts->z);
//		pts = pts->next;
//	}

//	ft_cube(&img);
							ft_printf("AFTER DRAW_MAP\n");
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
