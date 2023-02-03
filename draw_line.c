/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:25:14 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/03 16:30:18 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*colordst;

	colordst = img->addr + (img->line_len * y + (img->bpp / 8) * x);
	*(unsigned int *) colordst = color;
}

void	line_x(t_imgdata *img, t_coordinate pts, int color)
{
	int	dy;
	int	e;
	int	dx;
	int	inc[2];

	dy = ft_abs((pts.y2 - pts.y) * 2, '+');
	e = ft_abs(pts.x2 - pts.x, 'x');
	dx = e * 2;
	inc[0] = 1;
	inc[1] = 1;
	if (pts.y2 < pts.y)
		inc[1] = -1;
	if (pts.x >= pts.x2)
		inc[0] = -1;
	while (pts.x != pts.x2)
	{
		my_pixel_put(img, pts.x, pts.y, color);
		pts.x += inc[0];
		e -= dy;
		if (e <= 0)
		{
			pts.y += inc[1];
			e += dx;
		}
	}
}

void	line_y(t_imgdata *img, t_coordinate pts, int color)
{
	int	dy;
	int	e;
	int	dx;
	int	inc[2];

	dy = ft_abs((pts.y2 - pts.y) * 2, '+');
	e = ft_abs(pts.x2 - pts.x, 'x');
	dx = e * 2;
	inc[0] = 1;
	inc[1] = 1;
	if (pts.y2 < pts.y)
		inc[1] = -1;
	if (pts.x >= pts.x2)
		inc[0] = -1;
	while (pts.y != pts.y2)
	{
		my_pixel_put(img, pts.x, pts.y, color);
		pts.y += inc[1];
		e -= dx;
		if (e <= 0)
		{
			pts.x += inc[0];
			e += dy;
		}
	}
}

void	put_line(t_imgdata *img, t_coordinate pts, int color)
{
	int	dy;
	int	dx;

	dy = ft_abs((pts.y2 - pts.y) * 2, '+');
	dx = ft_abs((pts.x2 - pts.x) * 2, '+');
	if (dy <= dx)
		line_x(img, pts, color);
	else
		line_y(img, pts, color);
}
