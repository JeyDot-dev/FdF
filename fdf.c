/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:02 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/10 17:37:22 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
//t_imgdata .img .addr .bpp .line_len .endian
//t_line_coordinates .x .x2 .y .y2 .z .z2




int	main(int ac, char **av)
{
//	void			*mlx;
//	void			*mlx_win;
//	t_imgdata		img;
	t_pts_coordinates *pts;
	int	fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	pts = map_to_pts(fd);	
	while(pts->next)
	{
		printf("--x = %i, y = %i, z = %i\n", pts->x, pts->y, pts->z);
		pts = pts->next;
	}

//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "test window");
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
//	ft_cube(&img);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
}
