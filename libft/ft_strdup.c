/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:23:57 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/10/29 10:48:28 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*scpy;
	int		i;

	i = 0;
	scpy = (char *) malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!scpy)
		return (scpy);
	while (s[i])
	{
		scpy[i] = s[i];
		i++;
	}
	scpy[i] = 0;
	return (scpy);
}
