/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:37:30 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/23 12:55:17 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	hook_key_functions(int keycode, t_mlx_data *mlx)
{
	if (keycode == 65307 || keycode == 53)
		close_fdf(mlx);
	else if ((keycode > 65360 && keycode < 65365) ||
			(keycode > 122 && keycode < 127))
		hook_move_img(keycode %= 65360, *mlx);
	else if (keycode == 65453 || keycode == 65451 ||
			keycode == 69 || keycode == 78)
		hook_scale_img(keycode, *mlx);
	else if ((keycode > 47 && keycode < 52) || 
			(keycode > 17 && keycode < 30))
		hook_background(keycode, *mlx);
	return (0);
}

int	hook_background(int key, t_mlx_data mlx)
{
	if (key == 49 || key == 18)
		clear_img(&mlx.img, 1);
	else if (key == 50 || key == 19)
		clear_img(&mlx.img, 2);
	else if (key == 51 || key == 20)
		clear_img(&mlx.img, 3);
	else if (key == 48 || key == 29)
		clear_img(&mlx.img, -1);
	draw_map(mlx.pts, &mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	return (0);
}

int	hook_move_img(int direction, t_mlx_data mlx)
{
	translation_pts(mlx.pts, direction);
	clear_img(&mlx.img, 0);
	draw_map(mlx.pts, &mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	return (0);
}

void	hook_close_fdf(t_mlx_data *mlx)
{
	delete_list(mlx->pts);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	hook_scale_img(int scale, t_mlx_data mlx)
{
	scale %= 65450;
	clear_img(&mlx.img, 0);
	scale_pts(mlx.pts, scale);
	draw_map(mlx.pts, &mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	return (0);
}
