/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:24:01 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/17 19:54:40 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_list(t_pts_coordinates *pts)
{
	int	i;

	i = 1;
	while (pts)
	{
		ft_printf("---pts: %i, x=%i, y=%i, z=%i, color=%i\n", i,
			pts->x, pts->y, pts->z, pts->color);
		i++;
		pts = pts->next;
	}
}

void	delete_list(t_pts_coordinates *pts)
{
	t_pts_coordinates	*tmp;

	while (pts)
	{
		tmp = pts;
		pts = pts->next;
		free(tmp);
	}
}

t_pts_coordinates	*fdf_lstlast(t_pts_coordinates *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_pts_coordinates	*fdf_lstnew(int x, int y, int z)
{
	t_pts_coordinates	*new;

	new = malloc(sizeof(t_pts_coordinates));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->below = NULL;
	new->next = NULL;
	return (new);
}

void	add_struct(t_pts_coordinates **lst, t_pts_coordinates *new)
{
	t_pts_coordinates	*temp;

	if (!*lst && new)
		*lst = new;
	else if (lst && new && *lst)
	{
		temp = fdf_lstlast(*lst);
		temp->next = new;
	}
}
