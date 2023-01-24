/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:40:42 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/11/20 11:55:59 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	ftest(unsigned int i, char c)
{
	c += i;
	return (c);
}*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	long int	i;
	char		*str;

	i = -1;
	if (!s)
		return (NULL);
	str = ft_calloc(ft_strlen(s) + 1, sizeof(*str));
	if (!str)
		return (NULL);
	while (s[++i])
		str[i] = f((unsigned int) i, s[i]);
	return (str);
}
/*int	main(void)
{
	char	s[] = "012";
	char (*lel)(unsigned int, char) = ftest;
	char	*tst = ft_strmapi(s, lel);
	printf("resultat : %s\n", tst);
}*/
