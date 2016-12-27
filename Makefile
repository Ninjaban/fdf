#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/28 08:57:25 by jcarra            #+#    #+#              #
#    Updated: 2016/12/27 12:32:24 by jcarra           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf

SRC			=	ft_color.c \
				ft_fdf.c \
				ft_function.c \
				ft_draw.c \
				ft_init.c \
				ft_parsing.c \
				ft_read.c \
				ft_main.c

DIRSRC		=	sources/
DIRINC		=	include/
DIRLIB		=	minilibx/

SRCS		=	$(SRC:%=$(DIRSRC)%)
OBJS		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -I./$(DIRINC) -g3

LDFLAGS		=	-L/usr/X11/lib -L./minilibx -lmlx -lXext -lX11

CC			=	gcc
RM			=	rm -f
ECHO		=	printf
MAKE		=	make -C


all		:		$(NAME)
			   	@$(ECHO) ''

$(NAME)	:
				$(MAKE) $(DIRLIB)
				@$(CC) $(CFLAGS) -c $(SRCS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
				@$(ECHO) '\033[32m> Compiled\n\033[0m'
clean	:
				@$(RM) $(OBJS)
				@$(ECHO) '\033[31m> Directory cleaned\n\033[0m'
fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) '\033[31m> Remove executable\n\033[0m'
re		:		fclean all

lclean	:
				$(MAKE) $(DIRLIB) clean

lre		:
				$(MAKE) $(DIRLIB) re

.PHONY	:		all clean fclean re
