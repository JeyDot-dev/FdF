/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:30:20 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/17 13:30:40 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*colordst;

	colordst = img->addr + (img->line_len * y + (img->bpp / 8) * x);
	*(unsigned int *) colordst = color;
}
