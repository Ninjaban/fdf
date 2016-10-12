#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/28 08:57:25 by jcarra            #+#    #+#              #
#    Updated: 2016/07/28 08:59:49 by jcarra           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf

SRC			=	ft_fdf.c \
				ft_function.c \
				ft_draw.c \
				ft_init.c \
				ft_parsing.c \
				ft_read.c \
				ft_main.c

DIRSRC		=	sources/
DIRINC		=	include/

SRCS		=	$(SRC:%=$(DIRSRC)%)
OBJS		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -I./$(DIRINC) -g3

LDFLAGS		=	-L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11

CC			=	gcc
RM			=	rm -f
ECHO		=	printf


all		:		$(NAME)
			   	@$(ECHO) ''

$(NAME)	:
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

.PHONY	:		all clean fclean re
