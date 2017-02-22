/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:37:24 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/21 17:09:04 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void	ft_init_env(void)
{
	base.list_tiny = NULL;
	base.list_small = NULL;
	base.list_large = NULL;
}

void		ft_pushback(t_block *lst, t_block *new)
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
	if (b == (void *) -1)
		return (NULL);
	b->ptr = b->data;
	b->size = size;
	b->is_free = 0;
	b->next = NULL;
//	printf("MMAP %zu Adress: %p\n", size, b);
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
	t_block *new;
	int len;
	int i;

	lst->is_free = 0;
	lst->size = size;
	lst->ptr = lst->data;
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
		lst->next = new;
		lst = lst->next;
		i++;
	}
}

void	*malloc(size_t size)
{
	if (size <= 0)
		return (NULL);
	size = align8(size);
	if (base.list_tiny == NULL && base.list_small == NULL
			&& base.list_large == NULL)
		ft_init_env();
	if (size <= BLOCKTINY)
		return(ft_manage_tiny(size)->data);
	else if (size <= BLOCKSMALL)
		return(ft_manage_small(size)->data);
	else
		return (ft_manage_large(size)->data);
}
