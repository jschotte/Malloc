/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:34:16 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/11 12:09:24 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert(int nb, int b)
{
	int			i;
	int			j;
	static char	letter[16] = "0123456789ABCDEF";

	j = 0;
	if (nb < 0 && b == 10)
	{
		ft_putchar('-');
		j++;
		nb *= -1;
	}
	i = 1;
	while (nb / i > b - 1)
		i *= b;
	while (i != 0)
	{
		ft_putchar(letter[nb / i]);
		nb %= i;
		i /= b;
		j++;
	}
}

void	ft_itoa_base(int value, int base)
{
	int i;
	int j;

	if (value == -2147483648)
		ft_putstr("-2147483648");
	j = value;
	i = 0;
	while (j > 0)
	{
		j /= base;
		i++;
	}
	ft_convert(value, base);
}
