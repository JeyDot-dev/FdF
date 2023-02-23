/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:30:33 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/23 12:30:31 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_pts_coordinates *pts, t_imgdata *img)
{
	while (pts->next)
	{
		if (pts->below)
			draw_line(img, pts_to_line(to_isometric(*pts),
					to_isometric(*pts->below)));
		if (pts->link)
			draw_line(img, pts_to_line(to_isometric(*pts),
					to_isometric(*pts->next)));
		pts = pts->next;
	}
}
