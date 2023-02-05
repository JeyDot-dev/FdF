/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:25:14 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/05 17:16:44 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*colordst;

	colordst = img->addr + (img->line_len * y + (img->bpp / 8) * x);
	*(unsigned int *) colordst = color;
}
t_coordinate switch_pts(t_coordinate pts)
{
	int buffer;

	buffer = pts.x;
	pts.x = pts.x2;
	pts.x2 = buffer;
	buffer = pts.y;
	pts.y = pts.y2;
	pts.y2 = buffer;
	return (pts);
}
void	line_x(t_imgdata *img, t_coordinate pts, int color)
{
	int	dy;
	int	e;
	int	dx;
	int inc;

	dx = pts.x2 - pts.x;
	dy = pts.y2 - pts.y;
	inc = 1;
	if (dy < 0)
	{
		inc = -1;
		dy = -dy;
	}
	e = (2 * dy) - dx;
	while (pts.x < pts.x2)
	{
		my_pixel_put(img, pts.x, pts.y, color);
		if (e > 0)
		{
			pts.y += inc;
			e = e + (2 * (dy - dx));
		}
		else
			e = e + 2 * dy;
	}
}
void	line_y(t_imgdata *img, t_coordinate pts, int color)
{
	int	dy;
	int	e;
	int	dx;
	int inc;

	dx = pts.x2 - pts.x;
	dy = pts.y2 - pts.y;
	inc = 1;
	if (dx < 0)
	{
		inc = -1;
		dx = -dx;
	}
	e = (2 * dx) - dy;
	while (pts.y < pts.y2)
	{
		my_pixel_put(img, pts.x, pts.y, color);
		if (e > 0)
		{
			pts.x += inc;
			e = e + (2 * (dx - dy));
		}
		else
			e = e + 2 * dx;
	}
}

void	put_line(t_imgdata *img, t_coordinate pts, int color)
{
	int	dy;
	int	dx;

	dy = ft_abs(pts.y2 - pts.y);
	dx = ft_abs(pts.x2 - pts.x);
	if (dy <= dx)
	{
		if (pts.x > pts.x2)
			switch_pts(pts);
		line_x(img, pts, color);
	}
	else
	{
		if (pts.y > pts.y2)
			switch_pts(pts);
		line_y(img, pts, color);
	}
}
/*void put_line(t_imgdata *img, t_coordinate pts, int color)
{
	int dx;
	int dy;
	int p[2];
	int e;

	dx = pts.x2 - pts.x;
	dy = pts.y2 - pts.y;

	p[0] = pts.x;
	p[1] = pts.y;
	e = 2*dy-dx;
	while(p[0] < pts.x2)
	{
		if (e >= 0)
		{
			my_pixel_put(img, p[0], p[1], color);
			p[1] += 1;
			e = e + 2 * dy - 2 * dx;
		}
		else
		{
			my_pixel_put(img, p[0], p[1], color);
			e = e + 2 * dy;
		}
	p[0] += 1;
	}
}*/
