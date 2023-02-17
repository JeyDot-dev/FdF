/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:03:17 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/17 18:04:21 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pts_coordinates	to_isometric(t_pts_coordinates pts)
{
	double	a;
	double	b;

	a = 0.43;
	b = 2;
	pts.x = pts.x * cos(a) + pts.y * cos(a + b) + pts.z * cos(a - b);
	pts.y = pts.x * sin(a) + pts.y * sin(a + b) + pts.z * sin(a - b);
	return (pts);
}
