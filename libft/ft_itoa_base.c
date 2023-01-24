/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:17:29 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/11/30 09:38:10 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev_base(char *str, int nb)
{
	char	temp;
	int		i[2];

	i[0] = 0;
	i[1] = nb - 1;
	while (i[0] < nb / 2)
	{
		temp = str[i[1]];
		str[i[1]--] = str[i[0]];
		str[i[0]++] = temp;
	}
}

int	ft_ctalloc_base(unsigned long long int n, int basei)
{
	unsigned long long int	ct;

	ct = 0;
	if (n == 0)
		ct = 1;
	while (n != 0)
	{
		n = n / basei;
		ct++;
	}
	return (ct);
}

void	ft_p(char *s, char *bs, unsigned long long int nb, int to_oc)
{
	int	i;
	int	basei;

	basei = ft_strlen(bs);
	i = 0;
	while (i < to_oc)
	{
		s[i++] = bs[nb % basei];
		nb = nb / basei;
	}
}

char	*ft_itoa_base(unsigned long long int n, char *base)
{
	int			to_oc;
	char		*snb;

	to_oc = 0;
	to_oc = ft_ctalloc_base(n, ft_strlen(base));
	snb = ft_calloc(to_oc + 1, sizeof(*snb));
	if (!snb)
		return (NULL);
	ft_p(snb, base, n, to_oc);
	ft_strrev_base(snb, to_oc);
	return (snb);
}
