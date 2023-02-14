/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:30:33 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/14 19:33:14 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_pts_coordinates *pts, t_imgdata *img)
{
	while (pts)
	{
		if (pts->below)
			draw_line(img, pts_to_line(*pts, *pts->below), rgbo_color(250,0,0,0));

		ft_printf("Y=%i, nextY=%i\n", pts->y, pts->next->y);
		if (pts->next && pts->y == pts->next->y)
			draw_line(img, pts_to_line(*pts, *pts->next), rgbo_color(250,0,0,0));
		pts = pts->next;
	}
}
