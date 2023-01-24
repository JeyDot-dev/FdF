/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:08:19 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/10/24 15:30:26 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	nb;
	int				isneg;

	isneg = 0;
	nb = 0;
	while ((*str && *str >= 9 && *str <= 13) || (*str && *str == 32))
		str++;
	if (*str == 43)
		str++;
	else if (*str == 45)
	{
		str++;
		isneg = 1;
	}
	while (ft_isdigit(*str))
	{
		nb *= 10;
		nb += *str - 48;
		str++;
	}
	if (isneg == 1)
		nb *= -1;
	return ((int) nb);
}
