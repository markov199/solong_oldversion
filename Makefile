# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 12:12:10 by mkovoor           #+#    #+#              #
#    Updated: 2022/08/26 09:46:50 by mkovoor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS	= 	test.c


OBJS	=	${SRCS:.c=.o}

MLX_DIR		= ./minilibx
MLX_FLAGS	= -lmlx -lz -framework OpenGL -framework AppKit

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra
LFLAGS	=  -L $(MLX_DIR) -lmlx

%.o : %.c
	$(CC) -Imlx -c -o $@ $<

$(NAME)	:	$(OBJS)
		$(MAKE) -s -C $(MLX_DIR) all
		$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) $(LFLAGS)

all	:	$(NAME)


clean	:
			$(RM) $(OBJS) 
			$(MAKE) -s -C $(MLX_DIR) clean


fclean	:	clean
		$(RM) $(NAME)


re	:	fclean all

