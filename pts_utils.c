/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:54:00 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/17 12:24:21 by jsousa-a         ###   ########.fr       */
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

void	size_pts(t_pts_coordinates *pts)
{
	int inc = 20;

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
				//int i;
				//i=0;

	while (pts)
	{
//				ft_printf("pts:%i y=%i, z=%i\n", i, pts->y, pts->z);
		rgb = 255/55 * pts->z;
		pts->color = rgbo_color(rgb * 12, rgb * 3, rgb, 0);
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
void	origin_pts(t_pts_coordinates *pts, int w, int h)
{
	int base_x = w / 4;
	int base_y = h / 4;

	while(pts)
	{
		pts->x = base_x + pts->x;
		pts->y = base_y + pts->y;
		pts = pts->next;
	}
}
// LEFT = 65361 UP = 65362 RIGHT = 65363 DOWN = 65364
