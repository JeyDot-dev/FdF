/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:02:06 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/12/02 11:37:06 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	f(char *str)
{
	int	a;

	ft_putstr_fd(str, 1);
	a = ft_strlen(str);
	free(str);
	return (a);
}

int	nf(char *str)
{
	int	a;

	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr_fd(str, 1);
	a = ft_strlen(str);
	return (a);
}

int	ft_isparam(char c, va_list arg)
{
	if (c == 's')
		return (nf(va_arg(arg, char *)));
	else if (c == 'i' || c == 'd')
		return (f(ft_itoa(va_arg(arg, int))));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		return (1);
	}
	else if (c == 'x')
		return (f(ft_itoa_base(va_arg(arg, unsigned int), "0123456789abcdef")));
	else if (c == 'X')
		return (f(ft_itoa_base(va_arg(arg, unsigned int), "0123456789ABCDEF")));
	else if (c == 'u')
		return (f(ft_itoa_base(va_arg(arg, unsigned int), "0123456789")));
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (f(ft_itoa_base(va_arg(arg, unsigned long long int),
					"0123456789abcdef")) + 2);
	}
	else
		return (0);
}

int	ft_printf(const char *strparam, ...)
{
	va_list	args;
	int		i;
	int		ct;

	ct = 0;
	i = 0;
	va_start(args, strparam);
	while (strparam[i])
	{
		if (strparam[i] == '%')
		{
			ct += ft_isparam(strparam[i + 1], args);
			i += 2;
		}
		if (strparam[i] && strparam[i] != '%')
		{
			ft_putchar_fd(strparam[i++], 1);
			ct++;
		}
	}
	va_end(args);
	return (ct);
}
