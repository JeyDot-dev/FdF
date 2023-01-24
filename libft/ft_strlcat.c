/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:32:00 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/10/15 13:59:27 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* full size of DST, guarantee NUL if room.
 * appends SRC to end of DST. will append at most DSTSIZE - strlen(DST) - 1char.
 * then NUL-terminated unless dstsize = 0 || original strlen(DST) > DSTSIZE.
 * return (strlen(DST) + strlen(SRC)) */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ii;
	size_t	fix;

	fix = ft_strlen(dst);
	i = 0;
	ii = 0;
	if (dstsize < ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (dst[i])
		i++;
	if ((i + ft_strlen(src)) < dstsize)
		while (src[ii])
			dst[i++] = src[ii++];
	else
		while (i + 1 < dstsize)
			dst[i++] = src[ii++];
	if (dstsize)
		dst[i] = 0;
	return (fix + ft_strlen(src));
}
