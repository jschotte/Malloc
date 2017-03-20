/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:22:40 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/11 14:40:47 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

t_block		*ft_manage_tiny(size_t s)
{
	t_block	*b;

	if (g_base.list_tiny == NULL)
	{
		g_base.list_tiny = ft_createpage(PAGETINY);
		ft_split_page(g_base.list_tiny, BLOCKTINY, PAGETINY);
	}
	b = getfirstfree(g_base.list_tiny);
	if (b == NULL)
	{
		b = ft_createpage(PAGETINY);
		ft_split_page(b, BLOCKTINY, PAGETINY);
		ft_pushback(g_base.list_tiny, b);
	}
	b->size = s;
	b->is_free = 1;
	pthread_mutex_unlock(&g_base.lock);
	return (b);
}
