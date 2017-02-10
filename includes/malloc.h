/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:29:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/10 14:49:39 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <sys/resource.h>
# include "../libft/includes/libft.h"
# include <string.h>
# include <stdio.h>

# define TINY 100
# define SMALL 2024
# define BLOCK_SIZE sizeof(struct s_elem)
# define BDATA(b)	((void*)((char*)b + sizeof(t_elem) + 1))


typedef struct	s_elem
{
	int				is_free;
	size_t 			size;
	char 			data[1];
	struct s_elem	*next;
}				t_elem;

typedef struct	s_env
{
	struct s_elem	*lst_tiny;
	struct s_elem	*lst_small;
	struct s_elem	*lst_big;
}				t_env;

t_env 			base;

void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			free(void *ptr);
void			show_alloc_mem();

t_elem			*ft_manage_tiny(size_t s);
t_elem			*ft_manage_small(size_t s);
t_elem			*ft_manage_big(size_t s);

t_elem 			*ft_create_elem(size_t s);
t_elem			*ft_find_block(size_t s, t_elem **list);
t_elem			*ft_find_last(t_elem **list);

#endif
