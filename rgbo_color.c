/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbo_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:50:47 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/17 11:52:17 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	rgbo_color(int r, int g, int b, int o)
{
	int	color;

	color = 0;
	r = min_max_value(r);
	g = min_max_value(g);
	b = min_max_value(b);
	o = min_max_value(o);
	color |= b;
	color |= g << 8;
	color |= r << 16;
	color |= o << 24;
	return (color);
}
