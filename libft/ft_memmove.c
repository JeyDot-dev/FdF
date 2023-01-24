/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:07:12 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/10/13 17:01:17 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dsttemp;
	unsigned char	*srctemp;

	dsttemp = (unsigned char *) dst;
	srctemp = (unsigned char *) src;
	if (dst == NULL && src == NULL)
		return (dst);
	if (dst > src)
	{
		while (len-- > 0)
			dsttemp[len] = srctemp[len];
	}
	else
	{	
		while (len > 0)
		{
			*dsttemp = *srctemp;
			dsttemp++;
			srctemp++;
			len--;
		}
	}
	return (dst);
}
