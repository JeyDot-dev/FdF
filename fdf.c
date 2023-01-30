/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:41:02 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/01/30 12:02:10 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>

int rgb_hex(int r, int g, int b)
{
    int color = 0;
    color |= r;
    color |= g << 8;
    color |= b << 16;
    return (color);
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;

			int nb_pixels = 80;
			int	i = 0;
			//int	j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "test window");
	while (i < nb_pixels)
	{
		mlx_pixel_put(mlx, mlx_win, 1920/2 + (i / 3), 1080/2 + i, rgb_hex(56, 155, 155));
		i++;
	}
	mlx_loop(mlx);
}
