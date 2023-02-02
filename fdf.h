/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:56:19 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/02 15:52:05 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
typedef struct s_imgdata{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_imgdata;
typedef struct s_coordinate{
	int	x;
	int	x2;
	int	y;
	int	y2;
}				t_coordinate;
#endif
