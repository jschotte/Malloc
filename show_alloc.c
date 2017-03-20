/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:51:22 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/11 15:50:41 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void	display_list(t_block *lst)
{
	t_block	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putstr("|Adress:0x");
		ft_itoa_base((int)tmp->ptr, 16);
		ft_putstr("|Size:");
		ft_putnbr(tmp->size);
		ft_putstr("|isFree:");
		ft_putnbr(tmp->is_free);
		ft_putstr("|isHead:");
		ft_putnbr(tmp->ishead);
		ft_putstr("|\n");
		tmp = tmp->next;
	}
}

void	show_alloc_mem(void)
{
	ft_putstr("\nTINY\n");
	display_list(g_base.list_tiny);
	ft_putstr("SMALL\n");
	display_list(g_base.list_small);
	ft_putstr("LARGE\n");
	display_list(g_base.list_large);
}
