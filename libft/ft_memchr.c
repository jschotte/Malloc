/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:20:53 by jschotte          #+#    #+#             */
/*   Updated: 2016/03/15 08:57:10 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	d;

	i = 0;
	str = (unsigned char*)s;
	d = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == d)
			return (&(str[i]));
		i++;
	}
	return (NULL);
}
