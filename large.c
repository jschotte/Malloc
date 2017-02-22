/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:22:40 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/21 15:11:14 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"



t_block		*ft_manage_large(size_t s)
{
	t_block	*b;

	b = ft_createpage(s);
	b->is_free = 1;
	if (base.list_large == NULL)
	{
		base.list_large = b;
	}
	else
	{
		ft_pushback(base.list_large, b);
	}
	return (b);
}
