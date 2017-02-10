/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:51:22 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/10 14:26:29 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void	display_list(t_elem *lst)
{
	t_elem 	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		ft_putnbr(i);
		ft_putchar(':');
		ft_putnbr(tmp->is_free);
		ft_putchar(':');
		ft_putnbr(tmp->size);
		ft_putchar('\n');
		tmp = tmp->next;
		i++;
	}
}

void	show_alloc_mem()
{
	ft_putstr("\nTINY\n");
	display_list(base.lst_tiny);
	ft_putstr("SMALL\n");
	display_list(base.lst_small);
	ft_putstr("BIG\n");
	display_list(base.lst_big);
}
