/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:37:30 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/17 11:37:48 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	hook_background(int key, t_mlx_data mlx)
{
	if (key == 49)
		clear_img(&mlx.img, 1);
	else if (key == 50)
		clear_img(&mlx.img, 2);
	else if (key == 51)
		clear_img(&mlx.img, 3);
	else if (key == 48)
		clear_img(&mlx.img, -1);
	draw_map(mlx.pts, &mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	return(0);
}

int	hook_move_img(int direction, t_mlx_data mlx)
{
	translation_pts(mlx.pts, direction);
	clear_img(&mlx.img, 0);
	draw_map(mlx.pts, &mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	return(0);
}

int	hook_scale_img(int scale, t_mlx_data mlx)
{
	scale %= 65450;
	clear_img(&mlx.img, 0);
	scale_pts(mlx.pts, scale);
	draw_map(mlx.pts, &mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	return(0);
}
