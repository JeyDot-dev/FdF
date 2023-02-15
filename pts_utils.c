/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:54:00 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/15 11:12:28 by jsousa-a         ###   ########.fr       */
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
int	min_max_value(int color)
{
	if (color > 255)
		color = 255;
	if (color < 0)
		color = 0;
	return (color);
}
int	rgbo_color(int r, int g, int b, int o)
{
	int	color;

	color = 0;
	r = min_max_value(r);
	g = min_max_value(g);
	b = min_max_value(b);
	o = min_max_value(o);
	color |= b;
	color |= g << 8;
	color |= r << 16;
	color |= o << 24;
	return (color);
}
int	r_value(int color)
{
	int	red;

	red = (color >> 24 << 24 ^ color) >> 16;
	return (red);
}
int	g_value(int color)
{
	int	green;

	green = (color >> 16 << 16 ^ color) >> 8;
	return (green);
}
int	b_value(int color)
{
	int	blue;

	blue = (color >> 8 << 8 ^ color); 
	return (blue);
}
int	o_value(int color)
{
	int opacity;

	opacity = color >> 24; 
	return (opacity);
}
int	inc_color(int color, int target_color, int pixels)
{
	int	new_color;

	if (pixels <= 0)
		pixels = 1;
	new_color = color;
	if (color < target_color)
	{
		new_color = color + ((target_color - color) / pixels);
		if (new_color == color)
			new_color++;
		if (new_color > target_color)
			new_color = target_color;
	}
	else if (color > target_color)
	{
		new_color = color - ((color - target_color) / pixels);
		if (new_color == color)
			new_color--;
		if (new_color < target_color)
			new_color = target_color;
	}
	return (new_color);
}
int	smooth_colors(int color, int target_color, int pixels)
{
	int r;
	int g;
	int b;
	int o;

	r = inc_color(r_value(color), r_value(target_color), pixels);
	g = inc_color(g_value(color), g_value(target_color), pixels);
	b = inc_color(b_value(color), b_value(target_color), pixels);
	o = inc_color(o_value(color), o_value(target_color), pixels);
	return (rgbo_color(r, g, b, o));
}

void	scale_pts(t_pts_coordinates *pts)
{
	int inc = 50;

	while (pts)
	{	
		pts->x = inc * pts->x;
		pts->y = inc * pts->y;
		pts->z = 5 * pts->z;
		pts = pts->next;
	}
}

void	altitude_color(t_pts_coordinates *pts)
{
	int	rgb;
				int i;
				i=0;

	while (pts)
	{
				ft_printf("pts:%i y=%i, z=%i\n", i, pts->y, pts->z);
		rgb = 255/50 * pts->z;
		pts->color = rgbo_color(rgb + 25, rgb - 200, rgb - 200, 0);
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
