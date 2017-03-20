/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:22:40 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/11 15:17:52 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

size_t		find_sizelarge(size_t old)
{
	size_t new;

	new = PAGESIZE;
	while (new < old + sizeof(t_block))
		new += PAGESIZE;
	return (new);
}

t_block		*ft_manage_large(size_t s)
{
	t_block	*b;

	s = find_sizelarge(s);
	b = ft_createpage(s);
	b->is_free = 1;
	if (g_base.list_large == NULL)
		g_base.list_large = b;
	else
		ft_pushback(g_base.list_large, b);
	pthread_mutex_unlock(&g_base.lock);
	return (b);
}
