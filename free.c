/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:41:31 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/22 13:17:33 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void	ft_checkfree(t_block *lst, void *ptr, int s)
{
	int test;
	t_block *tmp;

	tmp = lst;
	test = 0;
	while (tmp && tmp->ptr != NULL && tmp->next)
	{
		if (tmp->is_free == 1)
			test = 1;
		tmp = tmp->next;
		printf("TEST\n");
	}
	if (test == 0)
	{
		//munmap(lst, s);
		//lst = NULL;
	}
}

int		ft_checklist(t_block *lst, void *ptr, int s)
{
	t_block *tmp;

	tmp = lst;
	while (tmp && tmp->ptr != ptr)
		tmp = tmp->next;
	if (tmp && tmp->ptr == ptr && tmp->is_free == 1)
	{
		tmp->is_free = 0;
		ft_checkfree(lst, ptr, tmp->size);
		return (1);
	}
	return (0);
}

void	free(void *ptr)
{
	if (ptr == NULL)
		return ;
	else if (ft_checklist(base.list_tiny, ptr, PAGETINY) == 1)
		return ;
	else if (ft_checklist(base.list_small, ptr, PAGESMALL) == 1)
		return ;
	else
		ft_checklist(base.list_large, ptr, 0);
}
