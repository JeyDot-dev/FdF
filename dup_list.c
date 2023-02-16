/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:12:08 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/16 17:39:21 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_pts_coordinates	*dup_struct(t_pts_coordinates pts)
{
	t_pts_coordinates	*new;

	new = malloc(sizeof(t_pts_coordinates));
	if (!new)
		return (NULL);
	new->x = pts.x;
	new->y = pts.y;
	new->z = pts.z;
	new->below = pts.below;
	new->next = pts.next;
	return (new);
}

void dup_list(t_pts_coordinates **new, t_pts_coordinates *pts)
{
	while (pts)
	{
		ft_printf("Loop dup\n");
		fdf_lstadd_back(new, dup_struct(*pts));
		pts = pts->next;
	}
}
