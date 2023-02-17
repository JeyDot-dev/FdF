/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:25:14 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/17 20:46:03 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line_coordinates	switch_pts(t_line_coordinates pts)
{
	int	buffer;

	buffer = pts.x;
	pts.x = pts.x2;
	pts.x2 = buffer;
	buffer = pts.y;
	pts.y = pts.y2;
	pts.y2 = buffer;
	buffer = pts.color;
	pts.color = pts.color2;
	pts.color2 = buffer;
	return (pts);
}

t_bresenham	populating_t_bresenham(t_bresenham ham,
				t_line_coordinates pts)
{
	ham.dx = pts.x2 - pts.x;
	ham.dy = pts.y2 - pts.y;
	ham.inc[0] = 1;
	if (ham.dx > ham.dy)
		ham.inc[1] = pts.x;
	else
		ham.inc[1] = pts.y;
	if (ham.dx > ham.dy && ham.dy < 0)
	{
		ham.inc[0] = -1;
		ham.dy = -ham.dy;
	}
	else if (ham.dy > ham.dx && ham.dx < 0)
	{
		ham.inc[0] = -1;
		ham.dx = -ham.dx;
	}
	return (ham);
}

void	line_x(t_imgdata *img, t_line_coordinates pts)
{
	t_bresenham	bres;

	bres = populating_t_bresenham(bres, pts);
	bres.e = (2 * bres.dy) - bres.dx;
	while (bres.inc[1] <= pts.x2)
	{
		if (pts.x <= 1920 && pts.y <= 1080
			&& pts.x >= 0 && pts.y >= 0)
			my_pixel_put(img, pts.x, pts.y, pts.color);
		pts.color = smooth_colors(pts.color, pts.color2, pts.x2 - pts.x);
		if (bres.e > 0)
		{
			pts.y += bres.inc[0];
			bres.e = bres.e + (2 * (bres.dy - bres.dx));
		}
		else
			bres.e = bres.e + 2 * bres.dy;
		pts.x += 1;
		bres.inc[1] += 1;
	}
}

void	line_y(t_imgdata *img, t_line_coordinates pts)
{
	t_bresenham	bres;

	bres = populating_t_bresenham(bres, pts);
	bres.e = (2 * bres.dx) - bres.dy;
	while (bres.inc[1] <= pts.y2)
	{
		if (pts.x <= 1920 && pts.y <= 1080
			&& pts.x >= 0 && pts.y >= 0)
			my_pixel_put(img, pts.x, pts.y, pts.color);
		pts.color = smooth_colors(pts.color, pts.color2, pts.y2 - pts.y);
		if (bres.e > 0)
		{
			pts.x += bres.inc[0];
			bres.e = bres.e + (2 * (bres.dx - bres.dy));
		}
		else
			bres.e = bres.e + 2 * bres.dx;
		pts.y += 1;
		bres.inc[1] += 1;
	}
}

void	draw_line(t_imgdata *img, t_line_coordinates pts)
{
	int	dy;
	int	dx;

	dy = ft_abs(pts.y2 - pts.y);
	dx = ft_abs(pts.x2 - pts.x);
	if (dy < dx)
	{
		if (pts.x > pts.x2)
			pts = switch_pts(pts);
		line_x(img, pts);
	}
	else
	{
		if (pts.y > pts.y2)
			pts = switch_pts(pts);
		line_y(img, pts);
	}
}

/*void put_line(t_imgdata *img, t_line_coordinates pts, int color)
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
