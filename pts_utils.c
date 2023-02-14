/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:54:00 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/14 22:44:47 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_line_coordinates	pts_to_line(t_pts_coordinates a, t_pts_coordinates b)
{
	t_line_coordinates new_line;

	new_line.x = a.x;
	new_line.y = a.y;
	new_line.color = a.color;
	new_line.x2 = b.x;
	new_line.y2 = b.y;
	new_line.color2 = b.color;
	return (new_line);
}

int	rgbo_color(int r, int g, int b, int o)
{
	int	color;

	color = 0;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	color |= o << 24;
	return (color);
}

void	scale_pts(t_pts_coordinates *pts)
{
	int inc = 50;

	while (pts)
	{	
		pts->x = inc * pts->x;
		pts->y = inc * pts->y;
		pts->z = 3 * pts->z;
		pts = pts->next;
	}
}

void	altitude_color(t_pts_coordinates *pts)
{
	int	rgb;

	rgb = 255/5 * pts->z+1;
	while (pts)
	{
		pts->color = rgbo_color(rgb + 100, rgb, rgb, 0);
		pts = pts->next;
	}
}
void	link_pts(t_pts_coordinates *pts)
{
	while (pts)
	{
		if(pts->next && pts->y == pts->next->y)
			pts->link = 1;
		else
			pts->link = 0;
		pts = pts->next;
	}
}
void	origin_pts(t_pts_coordinates *pts)
{
	int base_x = 1920 / 2;
	int base_y = 1080 / 2;

	while(pts)
	{
		pts->x = base_x + pts->x;
		pts->y = base_y + pts->y;
		pts = pts->next;
	}
}
