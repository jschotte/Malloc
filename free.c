/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:41:31 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/11 15:08:08 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void	ft_delete_largenode(t_block *lst, t_block **test)
{
	t_block *tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->is_free == 0)
			ft_delete_node(test, tmp->ptr);
		tmp = tmp->next;
	}
}

int		check_heap(t_block *lst)
{
	t_block	*tmp;
	int		nb;

	nb = 0;
	tmp = lst;
	while (tmp && nb < 2)
	{
		if (tmp->ishead == 1)
			nb++;
		tmp = tmp->next;
	}
	if (nb >= 2)
		return (1);
	else
		return (0);
}

void	ft_checkfree(t_block *lst, int s, int h, t_block **testl)
{
	int		test;
	int		c;
	t_block	*tmp;

	c = 0;
	tmp = lst;
	test = 0;
	while (tmp && c < h)
	{
		if (tmp->ishead == 1)
			c++;
		tmp = tmp->next;
	}
	while (tmp && tmp->ptr != NULL && tmp->next)
	{
		if (tmp->is_free == 1)
			test = 1;
		tmp = tmp->next;
	}
	if (test == 0 && check_heap(lst) == 1)
	{
		if (munmap(lst->ptr, s) != -1)
			ft_delete_allnode(h, lst, testl);
	}
}

int		ft_checklist(t_block *lst, void *ptr, int s, t_block **test)
{
	t_block	*tmp;
	int		h;

	h = 0;
	tmp = lst;
	while (tmp && tmp->ptr != ptr)
	{
		if (tmp->ishead == 1)
			h++;
		tmp = tmp->next;
	}
	if (tmp && tmp->ptr == ptr && tmp->is_free == 1)
	{
		tmp->is_free = 0;
		if (s == -1)
		{
			s = tmp->size;
			if (munmap(lst->ptr, s) != -1)
				ft_delete_largenode(lst, test);
		}
		else
			ft_checkfree(lst, s, h, test);
		return (1);
	}
	return (0);
}

void	free(void *ptr)
{
	pthread_mutex_lock(&g_base.lock);
	if (ptr == NULL)
		pthread_mutex_unlock(&g_base.lock);
	else if (ft_checklist(g_base.list_tiny, ptr,
				PAGETINY, &g_base.list_tiny) == 1)
		pthread_mutex_unlock(&g_base.lock);
	else if (ft_checklist(g_base.list_small, ptr,
				PAGESMALL, &g_base.list_small) == 1)
		pthread_mutex_unlock(&g_base.lock);
	else
	{
		ft_checklist(g_base.list_large, ptr, -1, &g_base.list_large);
		pthread_mutex_unlock(&g_base.lock);
	}
}
