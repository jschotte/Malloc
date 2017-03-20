/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 11:28:04 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/11 11:31:19 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void	ft_delete_node(t_block **head, void *val)
{
	t_block *tmp;
	t_block *prev;

	if (!head || !(*head))
		return ;
	tmp = *head;
	prev = NULL;
	while (tmp->ptr != val && tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp->ptr == val)
	{
		if (prev)
			prev->next = tmp->next;
		else
			*head = tmp->next;
	}
}

void	ft_delete_allnode(int h, t_block *lst, t_block **test)
{
	t_block *tmp;
	int		c;

	c = 0;
	tmp = lst;
	while (tmp && c < h)
	{
		if (tmp->ishead == 1)
			c++;
		tmp = tmp->next;
	}
	ft_delete_node(test, tmp->ptr);
	tmp = tmp->next;
	while (tmp && tmp->ishead == 0)
	{
		ft_delete_node(test, tmp->ptr);
		tmp = tmp->next;
	}
}
