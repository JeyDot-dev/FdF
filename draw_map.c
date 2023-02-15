/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:30:33 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/15 10:23:22 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_pts_coordinates *pts, t_imgdata *img)
{
	while (pts->next)
	{
		if (pts->below)
		{
					ft_printf("below colors 1:%i, 2:%i\n", pts->color, pts->below->color);
			draw_line(img, pts_to_line(*pts, *pts->below));
		}
		if (pts->link)
		{
					ft_printf("next colors 1:%i, 2:%i\n", pts->color, pts->next->color);
			draw_line(img, pts_to_line(*pts, *pts->next));
		}
		pts = pts->next;
	}
}
