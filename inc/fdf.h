/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:43:39 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/21 16:23:10 by jsousa-a         ###   ########.fr       */
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
	int		width;
	int		height;
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
typedef struct s_bresenham{
	int	dy;
	int	e;
	int	dx;
	int	inc[2];
}				t_bresenham;
typedef struct s_pts_coordinates{
	int							x;
	int							y;
	int							z;
	int							color;
	int							link;
	struct s_pts_coordinates	*next;
	struct s_pts_coordinates	*below;
}					t_pts_coordinates;

typedef struct s_mlx_data{
	void						*win;
	void						*mlx;
	struct s_imgdata			img;
	struct s_pts_coordinates	*pts;
}				t_mlx_data;

//pts value function
void				size_pts(t_pts_coordinates *pts);
void				origin_pts(t_pts_coordinates *pts, int width, int height);
void				link_pts(t_pts_coordinates *pts);
t_pts_coordinates	*map_to_pts(int fd);
t_line_coordinates	pts_to_line(t_pts_coordinates a, t_pts_coordinates b);
t_pts_coordinates	to_isometric(t_pts_coordinates pts);
//draw functions
void				draw_map(t_pts_coordinates *pts, t_imgdata *img);
void				draw_line(t_imgdata *img, t_line_coordinates pts);
void				my_pixel_put(t_imgdata *img, int x, int y, int color);
//color functions
int					rgbo_color(int r, int g, int b, int o);
void				altitude_color(t_pts_coordinates *pts);
int					smooth_colors(int color, int target_color, int pixels);
int					inc_color(int color, int target_color, int pixels);
int					min_max_value(int color);
//list utilities
void				dup_list(t_pts_coordinates **new, t_pts_coordinates *pts);
t_pts_coordinates	*dup_struct(t_pts_coordinates pts);
void				add_struct(t_pts_coordinates **lst, t_pts_coordinates *new);
void				print_list(t_pts_coordinates *pts);
void				delete_list(t_pts_coordinates *pts);
void				fill_list_line(int y, t_pts_coordinates *top_list,
						t_pts_coordinates **head, char **str);
t_pts_coordinates	*fdf_lstlast(t_pts_coordinates *lst);
t_pts_coordinates	*fdf_lstnew(int x, int y, int z);
//img utilities
t_imgdata			create_image(t_mlx_data mlx);
void				clear_img(t_imgdata *img, int col);
t_bresenham			populating_t_bresenham(t_line_coordinates pts);
//single color values
int					r_value(int color);
int					g_value(int color);
int					b_value(int color);
int					o_value(int color);
//hook functions
int					hook_background(int key, t_mlx_data mlx);
int					hook_move_img(int direction, t_mlx_data mlx);
int					hook_scale_img(int scale, t_mlx_data mlx);
int					hook_resize_functions(void);
int					hook_button_functions(t_mlx_data *mlx);
int					hook_key_functions(int keycode, t_mlx_data *mlx);

void				translation_pts(t_pts_coordinates *pts, int direction);
void				scale_pts(t_pts_coordinates *pts, int key);
void				close_fdf(t_mlx_data *mlx);
#endif
