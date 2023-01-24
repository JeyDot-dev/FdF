/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:40:58 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/10/15 14:48:53 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* full size of DST. guarantees NUL if room. 
 * copies dstsize -1 from src to dst. \0 if dstsize != 0.
 * return len of SRC
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (ft_strlen(src) < dstsize)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
	}
	if (dstsize)
		dst[i] = 0;
	return (ft_strlen(src));
}
