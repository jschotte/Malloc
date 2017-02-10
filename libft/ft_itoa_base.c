/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:08:03 by exam              #+#    #+#             */
/*   Updated: 2016/01/27 16:37:08 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_convert(int nb, char *str, int b, int i)
{
	int			j;
	const char	letter[16] = "0123456789ABCDEF";

	j = 0;
	if (nb < 0)
	{
		if (b == 10)
		{
			str[j] = '-';
			j++;
		}
		nb = -nb;
	}
	i = 1;
	while (nb / i > b - 1)
		i *= b;
	while (i != 0)
	{
		str[j] = letter[nb / i];
		nb %= i;
		i /= b;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char			*ft_itoa_base(int value, int base)
{
	int		i;
	int		j;
	char	*str;

	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		i = 0;
		j = value;
		while (j > 0)
		{
			i++;
			j = j / base;
		}
		str = (char*)malloc(sizeof(str) * i + 1);
		str = ft_convert(value, str, base, 0);
		return (str);
	}
}
