/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:58:59 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/17 18:01:31 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line_coordinates	pts_to_line(t_pts_coordinates a, t_pts_coordinates b)
{
	t_line_coordinates	new_line;

	new_line.x = a.x;
	new_line.y = a.y;
	new_line.color = a.color;
	new_line.x2 = b.x;
	new_line.y2 = b.y;
	new_line.color2 = b.color;
	return (new_line);
}

void	size_pts(t_pts_coordinates *pts)
{
	int	inc;

	inc = 50;
	while (pts)
	{	
		pts->x = inc * pts->x;
		pts->y = inc * pts->y;
		pts->z = inc / 4 * pts->z;
		pts = pts->next;
	}
}

void	altitude_color(t_pts_coordinates *pts)
{
	int	rgb;

	while (pts)
	{
		rgb = 255 / 55 * pts->z;
		pts->color = rgbo_color(rgb * 12, rgb * 3, rgb, 0);
		pts = pts->next;
	}
}

void	link_pts(t_pts_coordinates *pts)
{
	while (pts)
	{
		if (pts->next && pts->y == pts->next->y)
			pts->link = 1;
		else
			pts->link = 0;
		pts = pts->next;
	}
}

void	origin_pts(t_pts_coordinates *pts, int w, int h)
{
	int	base_x;
	int	base_y;

	base_x = w / 2;
	base_y = h / 6;
	while (pts)
	{
		pts->x = base_x + pts->x;
		pts->y = base_y + pts->y;
		pts = pts->next;
	}
}
