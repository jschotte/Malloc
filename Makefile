# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  jschotte<marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 20:29:39 by jschotte          #+#    #+#              #
#    Updated: 2017/03/11 15:34:03 by jschotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =  libft_malloc_$(HOSTTYPE).so

SRC = malloc.c \
	  free.c \
	  show_alloc.c \
	  tiny.c \
	  small.c \
	  large.c \
	  realloc.c \
	  calloc.c \
	  check_node.c \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB = "libft/libft.a"

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) -c $(CFLAGS) $(SRC)
	@$(CC) -lpthread -shared -o $(NAME) ./$(OBJ) $(LIB)
	@ln -s $(NAME) libft_malloc.so

all: $(NAME)

clean:
	@$(RM) ./$(OBJ)
	@make -C libft/ clean

fclean: clean
	@$(RM) $(NAME)
	@make -C libft/ fclean
	@$(RM) libft_malloc.so

re: fclean all

.PHONY: all clean fclean re
