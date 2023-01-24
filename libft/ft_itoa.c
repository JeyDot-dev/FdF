/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:17:29 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/11/19 16:57:01 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//TODO n == 0

void	ft_strrev(char *str, long int nb)
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

int	ctalloc(int n, long int ct)
{
	if (n == 0)
		ct = 1;
	while (n != 0)
	{
		n = n / 10;
		ct++;
	}
	return (ct);
}

void	populate(char *s, int neg, long int nb, int toalloc)
{
	int	i;

	i = 0;
	while (i < toalloc)
	{
		s[i++] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (neg == 1)
		s[i] = '-';
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			isneg;
	int			toalloc;
	char		*snb;

	toalloc = 0;
	isneg = 0;
	nb = (long int) n;
	if (nb < 0)
	{
		isneg = 1;
		nb *= -1;
	}
	toalloc = ctalloc(nb, toalloc);
	snb = ft_calloc(toalloc + 1 + isneg, sizeof(*snb));
	if (!snb)
		return (NULL);
	populate(snb, isneg, nb, toalloc);
	ft_strrev(snb, toalloc + isneg);
	return (snb);
}

/*int	main(void)
{
	int	tst;
	tst = -9;
	printf("%s", ft_itoa(tst));
}*/
