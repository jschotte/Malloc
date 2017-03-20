/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:29:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/11 15:49:39 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <sys/resource.h>
# include "../libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <pthread.h>

# define PAGESIZE getpagesize()

# define TINY 0
# define SMALL 1
# define LARGE 2

# define BLOCKTINY 128
# define BLOCKSMALL 1280

# define PAGETINY (4 * PAGESIZE)
# define PAGESMALL (48 * PAGESIZE)

# define ALIGN8(x) (((((x) - 1) / 8) * 8) + 8)

typedef struct	s_block
{
	int				is_free;
	size_t			size;
	struct s_block	*next;
	int				ishead;
	void			*ptr;
	char			data[];
}				t_block;

typedef struct	s_env
{
	struct s_block	*list_tiny;
	struct s_block	*list_small;
	struct s_block	*list_large;
	pthread_mutex_t	lock;
}				t_env;

t_env			g_base;

void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			free(void *ptr);
void			*calloc(size_t count, size_t size);
void			show_alloc_mem(void);

t_block			*ft_manage_tiny(size_t s);
t_block			*ft_manage_small(size_t s);
t_block			*ft_manage_large(size_t s);

t_block			*ft_create_block(size_t s);
t_block			*ft_createpage(size_t size);
void			ft_split_page(t_block *lst, int size, int max);
void			ft_pushback(t_block *lst, t_block *newblock);

t_block			*getfirstfree(t_block *b);
void			ft_delete_node(t_block **head, void *val);
void			ft_delete_allnode(int h, t_block *lst, t_block **test);

#endif
