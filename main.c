/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:22:21 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/10 15:13:03 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main()
{
	int i;
	char *addr;

	i = 0;
	while (i < 42)
	{
		addr=(char*)malloc(1024);
		addr[0]='a';
		ft_putchar(addr[0]);
		i++;
	}
	show_alloc_mem();
	return (0);
}
