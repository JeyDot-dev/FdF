/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:46:33 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/18 08:55:47 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hook_resize_functions(void)
{
	return (0);
}

int	hook_button_functions(t_mlx_data *mlx)
{
	close_fdf(mlx);
	return (0);
}
