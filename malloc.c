/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:37:24 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/11 15:20:35 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void	ft_pushback(t_block *lst, t_block *new)
{
	t_block *tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_block	*ft_createpage(size_t size)
{
	t_block	*b;

	b = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (b == (void *)-1)
	{
		pthread_mutex_lock(&g_base.lock);
		return (NULL);
	}
	b->ptr = b->data;
	b->size = size;
	b->is_free = 0;
	b->ishead = 1;
	b->next = NULL;
	return (b);
}

t_block	*getfirstfree(t_block *b)
{
	while (b && b->is_free != 0)
		b = b->next;
	return (b);
}

void	ft_split_page(t_block *lst, int size, int max)
{
	t_block	*new;
	int		len;
	int		i;

	lst->is_free = 0;
	lst->size = size;
	lst->ptr = lst->data;
	lst->ishead = 1;
	len = max / size;
	i = 0;
	len--;
	while (i < len)
	{
		new = lst->ptr + (size - sizeof(t_block));
		new->ptr = new->data;
		new->is_free = 0;
		new->size = size;
		new->next = NULL;
		new->ishead = 0;
		lst->next = new;
		lst = lst->next;
		i++;
	}
}

void	*malloc(size_t size)
{
	size = ALIGN8(size);
	if (!g_base.list_tiny && !g_base.list_small && !g_base.list_large)
	{
		g_base.list_tiny = NULL;
		g_base.list_small = NULL;
		g_base.list_large = NULL;
		pthread_mutex_init(&g_base.lock, NULL);
	}
	pthread_mutex_lock(&g_base.lock);
	if (size <= BLOCKTINY - sizeof(t_block))
		return (ft_manage_tiny(size)->data);
	else if (size <= BLOCKSMALL - sizeof(t_block))
		return (ft_manage_small(size)->data);
	else
		return (ft_manage_large(size)->data);
}
