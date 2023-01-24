/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:05:44 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/10/15 16:02:40 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	cc;

	cc = c;
	len = 0;
	while (s[len] != 0)
		len++;
	while (len && s[len] != cc)
		len--;
	if (s[len] == cc)
		return ((char *) s + len);
	else
		return (NULL);
}
