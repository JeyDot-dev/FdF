/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:02 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/17 12:24:21 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
//t_imgdata .img .addr .bpp .line_len .endian
//t_line_coordinates .x .x2 .y .y2 .z .z2
// LEFT = 65361 RIGHT = 65363 UP = 65362 DOWN = 65364
/*void	refresh_image(t_mlx_data mlx)
{
	mlx_destroy_image(mlx.mlx, mlx.img.img);
}*/

int	key_functions(int keycode, t_mlx_data *mlx)
{
	if (keycode == 65307)
	{
		ft_printf(GREEN "Successfuly closed fdf.\n" COLOR_RESET);
		exit(0);
	}
	if (keycode > 65360 && keycode < 65365)
	{
		keycode %= 65360;
		hook_move_img(keycode, *mlx);
	}
	if (keycode == 65453 || keycode == 65451)
		hook_scale_img(keycode, *mlx);
	if (keycode > 47 && keycode < 52)
		hook_background(keycode, *mlx);
	ft_printf("Keycode = %i\n", keycode);
	return(0);
//		mlx_destroy_window(mlx.mlx, mlx.win);
}

void	convert_pts(t_mlx_data mlx)
{
	link_pts(mlx.pts);
	altitude_color(mlx.pts);
	size_pts(mlx.pts);
	origin_pts(mlx.pts, mlx.img.width, mlx.img.height);
}
int	main(int ac, char **av)
{
	t_mlx_data			mlx;
	int					fd;

	if (ac != 2)
		return (-1);
	mlx.img.width = 1920;
	mlx.img.height = 1080;
	fd = open(av[1], O_RDONLY);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.img.width, mlx.img.height, "0/\
	1/2/3 = bg, arrow = move, +/- = zoom");
	mlx.img = create_image(mlx);
	mlx.pts = map_to_pts(fd);
	convert_pts(mlx);
	draw_map(mlx.pts, &mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L<<0, key_functions, &mlx);
//	mlx_hook(mlx.win, 2, 1L<<0, hook_move_img, &mlx.pts);
//	mlx_hook(mlx.win, 3, 1L<<1, hook_close_fdf, &mlx.pts);
	mlx_loop(mlx.mlx);
}
