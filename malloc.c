/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:37:24 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/10 14:00:50 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void	ft_init_env(void)
{
	base.lst_tiny = NULL;
	base.lst_small = NULL;
	base.lst_big = NULL;
}

t_elem	*ft_find_block(size_t s, t_elem **list)
{
	t_elem	*tmp;

	tmp = *list;
	while (tmp && !(tmp->is_free && s > tmp->size))
		tmp = tmp->next;

	return (tmp);
}

t_elem	*ft_find_last(t_elem **list)
{
	t_elem	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;

	return (tmp);
}

t_elem	*ft_create_elem(size_t s)
{
	t_elem	*b;

	b = mmap(0, BLOCK_SIZE + s, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	b->size = s;
	b->next = NULL;
	b->is_free = 1;
	return (b);
}

void	*malloc(size_t size)
{
	if (size <= 0)
		return (NULL);
	if (base.lst_tiny == NULL && base.lst_small == NULL
			&& base.lst_big == NULL)
		ft_init_env();
	if (size < TINY)
		return(ft_manage_tiny(size)->data);
	else if (size < SMALL)
		return(ft_manage_small(size)->data);
	else
		return (ft_manage_big(size)->data);
}
