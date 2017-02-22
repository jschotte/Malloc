# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  jschotte<marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 20:29:39 by jschotte          #+#    #+#              #
#    Updated: 2017/02/21 16:43:44 by jschotte         ###   ########.fr        #
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

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB = "libft/libft.a"

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) -c $(SRC)
	#@$(CC) -c $(CFLAGS) $(SRC)
	@$(CC) -shared -o $(NAME) ./$(OBJ) $(LIB)
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
