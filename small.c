/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:22:40 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/21 15:13:45 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

t_block		*ft_manage_small(size_t s)
{
	t_block	*b;

	if (base.list_small == NULL)
	{
		base.list_small = ft_createpage(PAGESMALL);
		ft_split_page(base.list_small, BLOCKSMALL, PAGESMALL);
	}
	b = getfirstfree(base.list_small);
	if (b == NULL)
	{
		b = ft_createpage(PAGESMALL);	
		ft_split_page(b, BLOCKSMALL, PAGESMALL);
		ft_pushback(base.list_small, b);		
	}
	b->is_free = 1;
	return (b);
}
