/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:39:37 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/17 09:57:20 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	fdf_lstadd_back(t_pts_coordinates **lst, t_pts_coordinates *new)
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
void	fdf_lstadd_front(t_pts_coordinates **lst, t_pts_coordinates *new)
{
	if (!lst && !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	add_pts_list(t_pts_coordinates **head, char *new_line)
{
	char	**split_line;
	t_pts_coordinates	*top_list;
	int		x;
	int		y;

	top_list = *head;
	x = 0;
	y = 0;
	split_line = ft_split(new_line, 32);
	if (*head != NULL)
	{
		y = 1;
		while (top_list->below)
		{
			y++;
			top_list = top_list->below;
		}
	}
	while (split_line[x])
	{
		fdf_lstadd_back(head, fdf_lstnew(x, y, ft_atoi(split_line[x])));
		if (y)
		{
			top_list->below = fdf_lstlast(*head);
			top_list = top_list->next;
		}
		x++;
	}
}

t_pts_coordinates	*map_to_pts(int fd)
{
	t_pts_coordinates	*head;
//	int					i;
	char				*new_line;

	head = NULL;
	while (1)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break;
		add_pts_list(&head, new_line);
		free(new_line);
	}
	close(fd);
	return (head);
}

