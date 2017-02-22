/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:22:40 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/22 11:32:50 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

t_block		*ft_manage_tiny(size_t s)
{
	t_block	*b;

	if (base.list_tiny == NULL)
	{
		base.list_tiny = ft_createpage(PAGETINY);
		ft_split_page(base.list_tiny, BLOCKTINY, PAGETINY);
	}
	b = getfirstfree(base.list_tiny);
	if (b == NULL)
	{
		b = ft_createpage(PAGETINY);	
		ft_split_page(b, BLOCKTINY, PAGETINY);
		ft_pushback(base.list_tiny, b);		
	}
	b->is_free = 1;
	return (b);
}
