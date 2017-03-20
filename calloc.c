/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:22:15 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/11 11:23:57 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void	*calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = NULL;
	if (count == 0)
		count++;
	ptr = malloc(count * size);
	bzero(ptr, count * size);
	return (ptr);
}
