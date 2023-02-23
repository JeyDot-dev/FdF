/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:17:26 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/23 12:55:45 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	translation_pts(t_pts_coordinates *pts, int direction)
{
	int	x;
	int	y;
	int	translation_ammount;

	x = 0;
	y = 0;
	translation_ammount = 10;
	if (direction == 1 || direction == 123)
		x = -translation_ammount;
	else if (direction == 2 || direction == 126)
		y = -translation_ammount;
	else if (direction == 3 || direction == 124)
		x = translation_ammount;
	else if (direction == 4 || direction == 125)
		y = translation_ammount;
	while (pts)
	{
		pts->x += x;
		pts->y += y;
		pts = pts->next;
	}
}

void	scale_pts(t_pts_coordinates *pts, int key)
{
	double	inc;
	int		x;
	int		y;
	int		z;

	inc = 1.1;
	x = pts->x / 10;
	y = pts->y / 10;
	z = pts->z / 10;
	if (key == 3 || key == 78)
	{
		inc = 0.9;
		x = -x;
		y = -y;
		z = -z;
	}
	while (pts)
	{	
		pts->x = inc * pts->x - x;
		pts->y = inc * pts->y - y;
		pts->z = inc * pts->z - z;
		pts = pts->next;
	}
}

void	close_fdf(t_mlx_data *mlx)
{
	delete_list(mlx->pts);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_printf(GREEN "Successfuly closed fdf.\n" COLOR_RESET);
	exit(0);
}
