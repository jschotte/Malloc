/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:22:40 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/10 15:15:58 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

t_elem		*ft_manage_small(size_t s)
{
	t_elem	*b;
	
	if (base.lst_small == NULL)
	{
		b = ft_create_elem(s);
		base.lst_small = b;
	}
	else
	{
		b = ft_create_elem(s);
		ft_find_last(&base.lst_small)->next = b;
	}
	return (b);
}
