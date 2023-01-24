/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:23:56 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/10/15 16:49:22 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	tf;
	unsigned char	*s2;

	tf = c;
	s2 = (unsigned char *) s;
	i = 0;
	if (!n)
		return (NULL);
	while (i + 1 < n && s2[i] != tf)
		i++;
	if (s2[i] == tf)
		return (&s2[i]);
	else
		return (NULL);
}
