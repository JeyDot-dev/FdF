/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:24:01 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/16 17:26:32 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_list(t_pts_coordinates *pts)
{
	int	i;

	i = 1;
	while (pts)
	{
		ft_printf("---pts: %i, x=%i, y=%i, z=%i, color=%i\n", i,
		pts->x, pts->y, pts->z, pts->color);
		i++;
		pts = pts->next;
	}
}
