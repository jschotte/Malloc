/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:51:22 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/21 16:56:06 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void	display_list(t_block *lst)
{
	t_block	*tmp;
	int 	i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->is_free == 0)
			printf(" |\x1b[35m%d\x1b[0m|Size:\x1b[33m%zu\x1b[0m|Adress:\x1b[36m%p\x1b[0m|isFree:\x1b[32m%d\x1b[0m|\n", i, tmp->size, tmp, tmp->is_free);
		else
			printf(" |\x1b[35m%d\x1b[0m|Size:\x1b[33m%zu\x1b[0m|Adress:\x1b[36m%p\x1b[0m|isFree:\x1b[31m%d\x1b[0m|\n", i, tmp->size, tmp->ptr, tmp->is_free);

		tmp = tmp->next;
		i++;
	}
}

void	show_alloc_mem()
{
	ft_putstr("\nTINY\n");
	display_list(base.list_tiny);
	ft_putstr("SMALL\n");
	display_list(base.list_small);
	ft_putstr("LARGE\n");
	display_list(base.list_large);
}
