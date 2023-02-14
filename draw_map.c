/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:30:33 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/14 22:02:33 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_pts_coordinates *pts, t_imgdata *img)
{
	while (pts->next)
	{
		if (pts->below)
		{
			ft_printf("Entering below...\n");
			draw_line(img, pts_to_line(*pts, *pts->below));
		}
		ft_printf("Y=%i, nextY=%i\n", pts->y, pts->next->y);
		if (pts->link)
		{
			ft_printf("Entering next...\n");
			draw_line(img, pts_to_line(*pts, *pts->next));
		}
		pts = pts->next;
		ft_printf("BEFORE NEXT LIST\n");
	}
}
