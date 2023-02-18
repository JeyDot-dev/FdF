/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:39:37 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/02/18 08:19:12 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_to_list(t_pts_coordinates **head, char *new_line)
{
	char				**split_line;
	t_pts_coordinates	*top_list;
	int					y;

	top_list = *head;
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
	fill_list_line(y, top_list, head, split_line);
}

void	fill_list_line(int y, t_pts_coordinates *top_list,
		t_pts_coordinates **head, char **str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		add_struct(head, fdf_lstnew(x, y, ft_atoi(str[x])));
		if (y)
		{
			top_list->below = fdf_lstlast(*head);
			top_list = top_list->next;
		}
		free(str[x]);
		x++;
	}
	free(str);
}

t_pts_coordinates	*map_to_pts(int fd)
{
	t_pts_coordinates	*head;
	char				*new_line;

	new_line = get_next_line(fd);
	if (!new_line)
	{
		printf(RED "INPUT_ERROR\n");
		exit(0);
	}
	head = NULL;
	map_to_list(&head, new_line);
	free(new_line);
	while (1)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
		map_to_list(&head, new_line);
		free(new_line);
	}
	close(fd);
	return (head);
}
