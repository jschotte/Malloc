/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:42:27 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/11 15:56:55 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

t_block	*find_block(void *ptr, t_block *lst)
{
	t_block *tmp;

	tmp = lst;
	while (tmp && tmp->ptr != ptr)
		tmp = tmp->next;
	if (tmp && tmp->ptr == ptr)
		return (tmp);
	else
		return (NULL);
}

void	*check_block(void *ptr, t_block *tmp, int type, size_t s)
{
	void	*new_ptr;
	t_block *new_block;

	if ((type == TINY && s <= BLOCKTINY - sizeof(t_block))
			|| (type == SMALL && s <= BLOCKSMALL - sizeof(t_block)))
	{
		tmp->size = s;
		return (ptr);
	}
	s = ALIGN8(s);
	new_ptr = malloc(s);
	if (s <= 128)
		new_block = find_block(new_ptr, g_base.list_tiny);
	else if (s <= 1024)
		new_block = find_block(new_ptr, g_base.list_small);
	else
		new_block = find_block(new_ptr, g_base.list_large);
	ft_memcpy(new_block->data, tmp->data, s);
	free(tmp->ptr);
	return (new_block->data);
}

void	*realloc(void *ptr, size_t size)
{
	t_block *old;
	int		type;

	if (ptr == NULL)
		return (malloc(size));
	if (size <= 0)
		return (NULL);
	size = ALIGN8(size);
	if ((old = find_block(ptr, g_base.list_tiny)) == NULL)
	{
		if ((old = find_block(ptr, g_base.list_small)) == NULL)
		{
			if ((old = find_block(ptr, g_base.list_large)) == NULL)
				return (NULL);
			else
				type = LARGE;
		}
		else
			type = SMALL;
	}
	else
		type = TINY;
	return (check_block(ptr, old, type, size));
}
