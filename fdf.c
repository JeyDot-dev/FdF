/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:02 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/16 21:02:07 by jsousa-a         ###   ########.fr       */
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

void	clear_img(t_imgdata *img)
{
	int	i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	while(i <= 1920 * 1080)
	{
		if (i % (1920 * 1080 / 1920 * 60) == 0)
			j += 2;
		tmp = img->addr + (img->bpp / 8) * i;
		*(unsigned int *) tmp = rgbo_color(80 + j, 80 + j, 180 + j, 0); 
		i++;
	}
}
// TODO Fix overflow in Y axis
t_imgdata	create_image(t_mlx_data mlx)
{
	t_imgdata	img;
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	return (img);
}
int	hook_move_img(int direction, t_mlx_data mlx)
{
	print_list(mlx.pts);
	translation_pts(mlx.pts, direction);
	clear_img(&mlx.img);
//	mlx_destroy_image(mlx.mlx, mlx.img.img);
//	mlx.img = create_image(mlx);
	print_list(mlx.pts);
	draw_map(mlx.pts, &mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	return(0);
}
int	hook_close_fdf(int keycode, t_mlx_data *mlx)
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
	ft_printf("Keycode = %i\n", keycode);
	return(0);
//		mlx_destroy_window(mlx.mlx, mlx.win);
}

void	convert_pts(t_pts_coordinates *pts)
{
	link_pts(pts);
	altitude_color(pts);
	scale_pts(pts);
	origin_pts(pts);
}
int	main(int ac, char **av)
{
	t_mlx_data			mlx;
	int					fd;

	if (ac != 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "test window");
	mlx.img = create_image(mlx);
	mlx.pts = map_to_pts(fd);
	print_list(mlx.pts);
	convert_pts(mlx.pts);
	ft_printf("Post_conversion\n");
	/*while (pts)
	{
		ft_printf("pts.x=%i\n, color=%i--", pts->x, pts->color);
		pts = pts->next;
	}*/
	draw_map(mlx.pts, &mlx.img);
							ft_printf("AFTER DRAW_MAP\n");
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);

	mlx_hook(mlx.win, 2, 1L<<0, hook_close_fdf, &mlx);
//	mlx_hook(mlx.win, 2, 1L<<0, hook_move_img, &mlx.pts);
//	mlx_hook(mlx.win, 3, 1L<<1, hook_close_fdf, &mlx.pts);
	mlx_loop(mlx.mlx);
}
