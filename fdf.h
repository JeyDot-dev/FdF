/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:56:19 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/15 09:52:34 by jsousa-a         ###   ########.fr       */
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
	int	color;
	int	color2;
}				t_line_coordinates;

typedef struct s_pts_coordinates{
	int	x;
	int	y;
	int	z;
	int	color;
	int	link;
	struct s_pts_coordinates *next;
	struct s_pts_coordinates *below;
}				t_pts_coordinates;

void				altitude_color(t_pts_coordinates *pts);
void				draw_line(t_imgdata *img, t_line_coordinates pts);
void				my_pixel_put(t_imgdata *img, int x, int y, int color);
void				ft_cube(t_imgdata *img);
void				to_isometric(t_pts_coordinates *pts);
t_pts_coordinates	*map_to_pts(int fd);
t_line_coordinates	pts_to_line(t_pts_coordinates a, t_pts_coordinates b);
int					rgbo_color(int r, int g, int b, int o);
void				scale_pts(t_pts_coordinates *pts);
void				origin_pts(t_pts_coordinates *pts);
void				draw_map(t_pts_coordinates *pts, t_imgdata *img);
void				link_pts(t_pts_coordinates *pts);
int					smooth_colors(int color, int target_color, int pixels);
int					inc_color(int color, int target_color, int pixels);
int					min_max_value(int color);

int					r_value(int color);
int					g_value(int color);
int					b_value(int color);
int					o_value(int color);
#endif
