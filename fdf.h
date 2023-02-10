/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:56:19 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/09 15:33:40 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# include <math.h>
typedef struct s_imgdata{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_imgdata;
typedef struct s_line_coordinates{
	int	x;
	int	x2;
	int	y;
	int	y2;
	int	z;
	int	z2;
}				t_line_coordinates;

typedef struct s_pts_coordinates{
	int	x;
	int	x2;
	int	y;
	int	y2;
	int	z;
	int	z2;
}				t_pts_coordinates;

void			put_line(t_imgdata *img, t_line_coordinates pts, int color);
void			my_pixel_put(t_imgdata *img, int x, int y, int color);
void			ft_cube(t_imgdata *img);
t_line_coordinates	to_isometric(t_line_coordinates pts);
#endif
