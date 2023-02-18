/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:02 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/18 08:56:57 by jsousa-a         ###   ########.fr       */
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

void	convert_pts(t_mlx_data mlx)
{
	link_pts(mlx.pts);
	altitude_color(mlx.pts);
	size_pts(mlx.pts);
	origin_pts(mlx.pts, mlx.img.width, mlx.img.height);
}

int	check_file_ext(char *file, char *ext)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((unsigned int) j < ft_strlen(ext) - 1 && file[i])
	{
		j = 0;
		while (ext[j] != file[i] && file[i])
			i++;
		while (ext[j] == file[i] && file[i])
		{
			i++;
			j++;
		}
	}
	if ((unsigned int) j == ft_strlen(ext) && file[i] == 0)
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_mlx_data			mlx;
	int					fd;

	if (ac != 2 || !check_file_ext(av[1], ".fdf"))
	{
		printf(RED "usage : ./fdf [file.fdf]\n" COLOR_RESET);
		exit(0);
	}
	fd = open(av[1], O_RDONLY);
	mlx.mlx = mlx_init();
	mlx.img.width = 1920;
	mlx.img.height = 1080;
	mlx.win = mlx_new_window(mlx.mlx, mlx.img.width, mlx.img.height, "0/1/2/3 = bg\
	\tarrow = move\t\t +/- = zoom");
	mlx.img = create_image(mlx);
	mlx.pts = map_to_pts(fd);
	convert_pts(mlx);
	draw_map(mlx.pts, &mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L << 0, hook_key_functions, &mlx);
	mlx_hook(mlx.win, 25, 1L << 18, hook_resize_functions, &mlx);
	mlx_hook(mlx.win, 17, 1L << 3, hook_button_functions, &mlx);
	mlx_loop(mlx.mlx);
}
