/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:22:40 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/10 12:28:50 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

t_elem		*ft_manage_big(size_t s)
{
	t_elem	*b;

	b = ft_create_elem(s);
	return b;
}
