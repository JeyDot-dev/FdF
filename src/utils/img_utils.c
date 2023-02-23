/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:32:26 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/23 12:36:02 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	clear_img(t_imgdata *img, int col)
{
	static int	base = -1;
	int			i;
	int			j;
	char		*tmp;

	if (col != 0)
		base = col;
	i = 0;
	j = 0;
	while (i <= (img->width * img->height) - 1)
	{
		if (i % (img->width * img->height / img->width * 60) == 0)
			j += 2;
		tmp = img->addr + (img->bpp / 8) * i;
		if (base == 1)
			*(unsigned int *) tmp = rgbo_color(0 + j, 90 + j, 130 + j, 0);
		else if (base == 2)
			*(unsigned int *) tmp = rgbo_color(120 + j, 40 - j, 140 - j, 0);
		else if (base == 3)
			*(unsigned int *) tmp = rgbo_color(200 - j, 100 - j, 20 + j, 0);
		else
			*(unsigned int *) tmp = 0;
		i++;
	}
}

t_imgdata	create_image(t_mlx_data mlx)
{
	t_imgdata	img;

	img.img = mlx_new_image(mlx.mlx, mlx.img.width, mlx.img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	img.width = mlx.img.width;
	img.height = mlx.img.height;
	return (img);
}
