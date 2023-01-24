/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:59:31 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/10/21 17:29:33 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char *big, const char *little, size_t i, size_t len)
{
	size_t	ii;

	ii = 0;
	while (big[ii] == little[ii] && i < len && little[ii])
	{
		ii++;
		i++;
	}
	if (!little[ii])
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*bigc;

	bigc = (char *) big;
	i = 0;
	if (!*little)
		return (bigc);
	while (bigc[i] && i < len)
	{
		if (bigc[i] == *little)
		{
			if (ft_check(&bigc[i], little, i, len))
				return (&bigc[i]);
		}
		i++;
	}
	return (NULL);
}
