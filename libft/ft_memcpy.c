/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:45:36 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/10/13 13:12:44 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstemp;
	unsigned char	*srctemp;

	dstemp = (unsigned char *) dst;
	srctemp = (unsigned char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*dstemp = *srctemp;
		dstemp++;
		srctemp++;
		n--;
	}
	return (dst);
}
